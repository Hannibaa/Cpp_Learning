/* the C++ Programming Language 4th edition Bjarn Strous 
      section 10.2.1 The Perser                            
      
   Here is a grammer for the language accepted by the calculator 
   
      program: 
            end                          // end is end-of-input
            expr_list end

      expr_list:
            expression print             // print is newline or semicolon
            expression print expr_list

      expression:
            expression + term
            expression - term
            term

      term:
            term / primary
            term * primary
            primary

      primary:
            number                       // number is a floating point literal
            name                         // name is an identifier
            name = expression
            - primary
            ( expression )

 In other word, a program is  a sequence of expression separated by semicolons. The basic units of an expression
 are numbers, names, and the operators *, /, +, - (both unary and binary), and = (assignement). Names need not
 be declared before use.
   I use a style of syntax analysis called RECURSIVE DESCENT; it is a popular and straightforward top-down 
 technique. In a language such as C++, in which functio calls are relatively cheap, it is also efficient. For
 each production in the grammer, there is a function that calls other functions. Terminal symbols (for example,
 end, number, +, and -) are recognized by a lexical analyzer and nonterminal symbols are recongnized by syntax 
 analyzer functions, expr(), term() and prim(). As soon as both operands of a (sub)expression are known, the 
 expression is evaluated; in a real compiler, code could be generated at this point.
   For input, the parser uses a Token_stream that encapsulates the reading of characters and their composition
 into Tokens. That is, a Token_stream 'tokenizes': it turns streams of characters, such as 123.45, into Tokens.
 A Token is a {kind-of-token,value} pair, such as {number,123.45}, where the 123.45 has been turned into a 
 floating point value. The main parts of the parser need only to know the name of the Token_stream, ts, and how
 to get Tokens from it. To read the next Token, it calls ts.get(). To get the most recently read Token(the '
 current token'), it calls ts.current(). In addition to providing tokenizing, the Token_stream hides the actual
 source of the characters. We'll see that they can come directly form user typing to cin, from a program command
 line, or from any other input stream.

     the definition of Token looks like this:
            
            */

#include <iostream>
#include <string>
#include <map>
#include "c:\Users\Acer\source\MyLib/Console_Library/escape_code.h"


using namespace std;

enum class Kind : char {
    name, number, end,
    plus = '+', minus = '-' , mul = '*' , div = '/' , print = ';' , assign = '=' ,
    lp = '(', rp = ')'
};

struct Token {               // Reprensenting each token by  the integer value of its character is convenient
    Kind kind;               // and efficient and can be a help to people using debuggers. This work as long as
    string string_value;     // no character used as input has a value used as an enumberator - and no current
    double number_value;     // character set I know of has a printing character with a single-digit integer
};                           // value.


class Token_stream {
public:
    Token_stream(istream& s) : ip{&s},owns{false}{}
    Token_stream(istream* p):ip{p},owns{true}{}

    ~Token_stream() { close(); }

    Token get()            // read and return next token
    {
        char ch = 0;
        *ip >> ch;

        switch(ch) {
        case 0:
            return ct = { Kind::end };// assign and return
        case ';': // end of expression; print
        case '*':
        case '/':
        case '+':
        case '-':
        case '(':
        case ')':
        case '=':
            return ct == {static_cast<Kind>(ch)};
        case '0':case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
        case '.':
            ip->putback(ch);  // put the first digit (or.)back  into input stream
            *ip >> ct.number_value;  // read number into ct
            ct.kind = Kind::number;
            return ct;
        default:   // name, name = ,or error
            if (isalpha(ch)) {
                ip->putback(ch); // put the first character back into input stream
                *ip >> ct.string_value; // read string into ct
                ct.kind = Kind::name;
                return ct;
            }

            std::cout << "bad error\n";
            return ct = { Kind::print };
        }
    }

    const Token& current();   // most recently read token

    void set_input(istream& s) { close(); ip = &s; owns = false; }
    void set_input(istream* p) { close(); ip = p; owns = true; }

private:
    void close() { if (owns) delete ip; }

    istream* ip;              // pointer to an input steam
    bool     owns;            // does the Token_stream own the istream?
    Token ct{ Kind::end };    // current token
};

Token_stream ts;
map<string, double> table;

double expr(bool get)         // add and subtract
{
    double left = term(get);

    for (;;) {
        switch (ts.curent().kind) {
        case Kind::plus:
            left += term(true);
            break;
        case Kind::minus:
            left -= term(true);
            break;
        default:
            return left;
        }
    }
}

double term(bool get) {
    double left = prim(get);

    for (;;) {
        switch (ts.current().kind) {
        case Kind::mul:
            left* = prim(true);
            break;
        case Kind::div:
            if (auto d = prim(true)) {
                left /= d;
                break;
            }
            return std::cout << "divide by 0\n";
        default:
            return left;
        }
    }
}

double prim(bool get) {  // handle primaries
    if (get) ts.get(); // read next token

    switch (ts.current().kind) {
    case Kind::number:  // floating point
    {
        double v = ts.current().number_value;
        ts.get();
        return v;
    }
    case Kind::name:
    {
        double& v = table[ts.current().string_value]; // find the corresponding
        if (ts.get().kind == Kind::assign) v = expr(true);
        return v;
    }
    case Kind::minus: // unary minus
        return -prim(true);
    case Kind::lp:
    {
        auto e = expr(true);
        if (ts.current().kind != Kind::rp) return std::cout << "( expected\n";
        ts.get();   // eat )
        return e;
    }
    default:
        return std::cout << "primary expected\n";
    }
}

int main()
{



    cin.get();
    return 0;
}