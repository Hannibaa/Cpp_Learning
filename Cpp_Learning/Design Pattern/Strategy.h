#pragma once
#include <iostream>
#include <memory>
#include "MyLib/Console_Library/escape_code.h"


/*
       Strategy Pattern as described by Mike Shah
       Behavioral Pattern

*/

// We now have multiple Sorts implementing from a common interface 
// first exemple using plymorphism to chose algorithm

namespace sol1 {

    struct ISorts {
        ~ISorts() {}

        virtual void Sort() = 0;
    };

    struct InsersionSort : public ISorts {
        void Sort() override  {
            Print_(color::Green, "Insersion Sort App") << end_;
        }
    };

    struct BubbleSort : public ISorts {
        void Sort() override {
            Print_(color::Fuchsia, "Bubble Sort App") << end_;
        }
    };

    struct QuickSort : public ISorts {
        void Sort() override {
            Print_(color::Red, "Quick Sort App") << end_;
        }
    };
}


namespace sol2 {

    // Interface want to enforce.
    // for differente bahavior
    struct ICombat {
        virtual ~ICombat() {};

        virtual void Execute() = 0;
    };

    struct NoCombat : public ICombat {
        void Execute() override {
            Print_(color::Green, "No Combat") << end_;
        }
    };

    struct Combat : public ICombat {
        void Execute() override {
            Print_(color::Red, "Start Combat") << end_;
        }
    };

    // Context Shipe
    struct Shipe {

        Shipe() {
            m_CombatStrategy = std::make_unique<NoCombat>();
        }

        void setStrategy(std::unique_ptr<ICombat>&& combat) {
            m_CombatStrategy = std::move(combat);
        }

        void DoActions() {
            m_CombatStrategy->Execute();
        }

    private:

        std::unique_ptr<ICombat> m_CombatStrategy;
    };

}