/**
 * @file    ex_01.cpp
 * @author  M Morella
 * @brief   Prints personal information about me, in stunning 4-bit color!
 * 
 * Execute binary with -c flag to enable ANSI color in output. 
 */

#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    // check for -c flag, then enable or disable color constants.
    std::string RSET, BGRN, BBLU, ACNT;
    bool color_support = false;
    for  (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        if (arg == "-c" || arg == "--color") {
            color_support = true;
        } else {
            std::cout << "usage:\n"
                      << "-c  --color  Enable color";
            exit(1);
        }
        break;
    }
    if (color_support) {
        RSET = "\x1b[0m";
        // ANSI code to make text use bold green
        BGRN = RSET + "\x1b[1;" + (std::to_string(32)) + "m";
        // ANSI code to make text use blue
        BBLU = RSET + "\x1b[1;" + (std::to_string(34)) + "m";
        // ANSI code to make text use an accent color (33=yellow)
        ACNT = RSET + "\x1b[" + (std::to_string(33)) + "m";
    }
    // prints an accented bullet point for items in a list
    std::string ASTX = ACNT + " * " + RSET;
    // print an accented arrow for separating strings
    std::string ARRW = ACNT + " → " + RSET;

    std::cout << '\n'; // print an extra line of separation between the invoking command and the output
    std::cout << BGRN + "Name" + ARRW + "M Morella (She/They)" + '\n';
    std::cout << '\n';
    std::cout << BGRN + "Hometown\t" + ARRW + "Alpharetta" + '\n';
    std::cout << BGRN + "High School\t" + ARRW + "Milton High School" + '\n';
    std::cout << BGRN + "Occupation\t" + ARRW + "Studying online, not getting the coronavirus." + '\n';
    std::cout << '\n';
    std::cout << BGRN + "Comp Sci Courses I've Taken" + ARRW + '\n';
    std::cout << ASTX + "APCS\t\t- AP Computer Science" + '\n';
    std::cout << ASTX + "CSE 1322\t- Programming II" + '\n';
    std::cout << ASTX + "MATH 2202\t- Calculus II" + '\n';
    std::cout << ASTX + "MATH 2345\t- Discrete Mathematics" + '\n';
    std::cout << '\n';
    std::cout << BGRN + "Computers I Use" + ARRW + '\n';
    std::cout << ASTX + "Desktop \"Gaming\" PC\t" + BBLU + "[GTX 1060]\t(Windows 10)" + '\n';
    std::cout << ASTX + "Macbook Pro 2015 \t" + BBLU + "[i5-5287U]\t(macOS 10.15)" + '\n';
    std::cout << ASTX + "iPhone 11 \t\t" + BBLU + "[64 GB]\t\t(iOS 14 Beta)" + '\n';
    std::cout << ASTX + "Google Pixel XL  \t" + BBLU + "[128 GB]\t(Android 10)" + '\n';
    std::cout << '\n';
    std::cout << BGRN + "Hobbies of Mine" + ARRW + '\n';
    std::cout << ASTX + "Singing in Choir" + '\n';
    std::cout << ASTX + "Playing and Developing Video Games" + '\n';
    std::cout << ASTX + "Cooking Food" + '\n';
    std::cout << '\n';
    std::cout << BGRN + "After I graduate, I hope to" + ARRW + "Be employed.";
    std::cout << '\n'; // be kind, newline.
    std::cout << '\n'; // and a second one, just for looks
    return 0;
}