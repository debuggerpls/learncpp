#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <ctime>

namespace q1
{
    namespace enums
    {
        enum Items
        {
            Item_Potion,
            Item_Torch,
            Item_Arrow,
            Item_Max
        };
    }

    struct Player
    {
        Player(){};
        Player(int potions, int torches, int arrows);
        int countTotalItems();

        std::array<int, enums::Item_Max> items;
    };

    Player::Player(int potions, int torches, int arrows)
    {
        items[enums::Item_Potion] = potions;
        items[enums::Item_Torch] = torches;
        items[enums::Item_Arrow] = arrows;
    }

    int Player::countTotalItems()
    {
        return std::accumulate(items.begin(), items.end(), 0);
    }
}

namespace q2
{
    struct Student
    {
        int grade;
        std::string name;
    };

    struct StudentList
    {
        StudentList();
        void populate();
        void sort();
        void print();
        std::vector<Student> v;
    };

    bool sortFnc(const Student &s1, const Student &s2)
    {
        return (s1.grade > s2.grade);
    }

    StudentList::StudentList()
    {
        populate();
        print();
        sort();
        print();
    }

    void StudentList::populate()
    {
        std::cout << "How many students: ";
        int cnt{};
        std::cin >> cnt;
        std::string name{};
        int grade{};

        for (; cnt > 0; --cnt)
        {
            std::cout << "Enter students name: ";
            std::cin >> name;
            std::cout << name << "'s grade: ";
            std::cin >> grade;
            v.push_back(q2::Student{grade, name});
        }

        std::cout << '\n';
    }

    void StudentList::sort()
    {
        std::sort(v.begin(), v.end(), sortFnc);
    }

    void StudentList::print()
    {
        for (auto &s: v)
        {
            std::cout << s.name << " got a grade of " << s.grade << '\n';
        }
        std::cout << '\n';
    }

}

namespace q3
{
    void swap(int &i1, int &i2)
    {
        int tmp{i1};
        i1 = i2;
        i2 = tmp;
    }

    void test()
    {
        std::cout << "Enter two integers: ";
        int i1{};
        int i2{};
        std::cin >> i1 >> i2;

        std::cout << "Before: i1=" << i1 << "; i2=" << i2 << '\n';
        swap(i1, i2);
        std::cout << "After: i1=" << i1 << "; i2=" << i2 << '\n';

    }
}

namespace q4
{
    void printString(const char *s)
    {
        while(*s != 0)
        {
            std::cout << *s;
            ++s;
        }

        std::cout << '\n';
    }
}

namespace q6
{
    enum class Card_Rank
    {
        Rank_2 = 2,
        Rank_3,
        Rank_4,
        Rank_5,
        Rank_6,
        Rank_7,
        Rank_8,
        Rank_9,
        Rank_10,
        Rank_J,
        Rank_Q,
        Rank_K,
        Rank_A,

        MAX_RANKS,
    };

    enum class Card_Suit
    {
        Suit_Clubs = 'C',
        Suit_Diamonds = 'D',
        Suit_Hearts = 'H',
        Suit_Spades = 'S',

        MAX_SUITS,
    };

    struct Card
    {
        Card_Rank rank;
        Card_Suit suit;
    };

    void printCard(const Card &c)
    {
        switch (c.rank)
        {
            case Card_Rank::Rank_J:
                std::cout << 'J'; break;
            case Card_Rank::Rank_Q:
                std::cout << 'Q'; break;
            case Card_Rank::Rank_K:
                std::cout << 'K'; break;
            case Card_Rank::Rank_A:
                std::cout << 'A'; break;
            default:
                std::cout << static_cast<int>(c.rank); // MAX_RANKS and unknown is printed aswell
        }

        std::cout << static_cast<char>(c.suit);
    }

    std::array<Card, 52> createDeck()
    {
        std::array<Card, 52> deck{};
        int cnt{0};

        for (auto i{static_cast<int>(Card_Rank::Rank_2)};
            i < static_cast<int>(Card_Rank::MAX_RANKS);
            ++i)
        {
            Card_Rank rank = static_cast<Card_Rank>(i);

            deck[cnt].rank = rank;
            deck[cnt++].suit = Card_Suit::Suit_Clubs;

            deck[cnt].rank = rank;
            deck[cnt++].suit = Card_Suit::Suit_Diamonds;

            deck[cnt].rank = rank;
            deck[cnt++].suit = Card_Suit::Suit_Hearts;

            deck[cnt].rank = rank;
            deck[cnt++].suit = Card_Suit::Suit_Spades;
        }

        return deck;
    }

    void printDeck(const std::array<Card, 52> &deck)
    {
        for (auto &card: deck)
        {
            printCard(card);
            std::cout << " ";
        }

        std::cout << '\n';
    }

    void shuffleDeck(std::array<Card, 52> &deck)
    {
        static std::mt19937 rnd{ static_cast<std::mt19937::result_type>(std::time(nullptr))};
        
        std::shuffle(deck.begin(), deck.end(), rnd);
    }

    int getCardValue(const Card &card)
    {
        int rank{0};

        switch(card.rank)
        {
            case Card_Rank::Rank_J:
            case Card_Rank::Rank_Q:
            case Card_Rank::Rank_K:
                rank = 10; break;
            case Card_Rank::Rank_A:
                rank = 11; break;
            default:
                rank = static_cast<int>(card.rank); break;
        }
        return rank;
    }

    // Question #7
    bool playBlackjack(std::array<Card, 52> &deck)
    {
        static int index{0};

        int playerScore{0};
        int dealerScore{0};

        std::cout << "\nDealer draws: ";
        printCard(deck.at(index));
        dealerScore += getCardValue(deck.at(index));
        std::cout << ". \tScore: " << dealerScore << "\n\n";
        
        if (++index >= 51) 
            index = 0;

        std::cout << "You draw: ";
        printCard(deck.at(index));
        playerScore += getCardValue(deck.at(index));
        std::cout << " ";
        if (++index >= 51) 
            index = 0;
        printCard(deck.at(index));
        playerScore += getCardValue(deck.at(index));
        std::cout << ". \tScore: " << playerScore << "\n\n";
        if (++index >= 51) 
            index = 0;

        int input{};
        do
        {
            std::cout << "Enter 1 (hit) or 0 (stand): ";
            std::cin >> input;
            if (input != 0)
            {
                std::cout << "You draw: ";
                printCard(deck.at(index));
                playerScore += getCardValue(deck.at(index));
                if (++index >= 51) 
                    index = 0;
                std::cout << ". \t\tScore: " << playerScore << '\n';
                if (playerScore == 21)
                {
                    input = 0;
                }
                else if (playerScore > 21)
                {
                    return false;
                }
            }
        } while (input != 0);
        
        while (dealerScore < 17)
        {
            std::cout << "Dealer draws: ";
            printCard(deck.at(index));
            dealerScore += getCardValue(deck.at(index));
            std::cout << ". \tScore: " << dealerScore << '\n';
            if (++index >= 51) 
                index = 0;

            if (dealerScore > 21)
            {
                return true;
            }    
        }

        return (playerScore > dealerScore);
    }

}

int main()
{
    /*
    q1::Player player{2, 5, 10};

    std::cout << "Player has: " << player.countTotalItems() << " items and " 
                << player.items[q1::enums::Item_Arrow] << " arrows.\n";
    */

    //q2::StudentList l; // kodel l() neveikia?

    //q3::test();

    //q4::printString("Hello, world!");

    auto deck{q6::createDeck()};
    q6::printDeck(deck);
    q6::shuffleDeck(deck);
    q6::printDeck(deck);

    if (q6::playBlackjack(deck))
        std::cout << "Player wins!\n";
    else
    {
        std::cout << "Dealer wins!\n";
    }
    

    return 0;
}