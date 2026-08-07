// Lab IV: Arrays and Strings
// Programming Essentials for Astronomy I - C++
//
// This file is a skeleton. It gives you the STRUCTURE of the program - the
// order things go in, and what each piece is for - and nothing else. You write
// all of the code yourself. The README has worked examples of the syntax to
// get you going; turning them into the exercises is your job.
//
// Compile and run with:
//     g++ arrays_and_strings.cpp -o arrays_and_strings
//     ./arrays_and_strings
//
// Keep the exercise comments in place as you go, so your submission is easy to
// follow.

// TODO: include the three headers you need - <iostream>, <string>, and
// <cctype> (the last one is where std::toupper lives).
    #include <iostream> 
    #include <string>
    #include <cctype>

    double mean(const double data[], int n);
    int indexOfMin(const double data[], int n);
    int indexOfMax(const double data[], int n);
    int indexBright(const double data[], int n);
    std::string toUpper(std::string text);
// ---------------------------------------------------------------------------
// Our star catalogue: three parallel arrays of length 8, so that index i
// describes the same star in all three - names, distance and magnitude.
// ---------------------------------------------------------------------------

// TODO: declare the three arrays. The eight stars and their values are in the
// README.
    std::string names[8] = {"Sirius", "Canopus", "Alpha Centauri", "Arcturus", "Vega", "Rigel", "Procyon", "Betelgeuse"};
    double distance[8] = {8.6, 310.0, 4.4, 37.0, 25.0, 860.0, 11.5, 640.0};
    double magnitude[8] = {-1.46, -0.74, -0.27, -0.05, 0.03, 0.13, 0.34, 0.42};

// --- Part A: functions over arrays -----------------------------------------
// Exercise 2: the average of the first n values of an array of doubles.
// TODO: write a function that adds the values up in a loop, then divides by n.
    double mean(const double data[], int n){

        double total_distance = 0;

        for (int i = 0; i <= n; i++){
            total_distance = total_distance + data[i];
        }

        return (total_distance/n);
}

// Exercise 3: the INDEX of the smallest value in an array of doubles.
// TODO: write a function that assumes index 0 is smallest, then checks the rest.
    int indexOfMin(const double data[], int n){

        double smallest = data[0];
        int index = 0;

        for (int i = 0; i < n; i++){
            if (smallest > data[i]){
                smallest = data[i];
                index = i;
            }
        }

        return index;
}

// Exercise 3 (cont.): the INDEX of the largest value.
// TODO: write a function the same shape as the one above, looking for the
// largest value instead.
    int indexOfMax(const double data[], int n){

        double largest = data[0];
        int index = 0;

        for (int i = 0; i <= n; i++){
            if (largest < data[i]){
                largest = data[i];
                index = i;
            }
        }

        return index;
}

// Exercise 4
    int indexBright(const double data[], int n){

        double brightest = data[0];
        int index = 0;

        for (int i = 0; i <= n; i++){
            if (brightest > data[i]){
                brightest = data[i];
                index = i;
            }
        }

        return index;
}

// --- Part B: functions over strings ----------------------------------------

// Exercise 7: a string with every letter capitalised.
// TODO: write a function that loops over each character and uses
// std::toupper(...) on it.
    std::string toUpper(std::string text){
       for (int i = 0; i <= text.length(); i++){
        text[i] = std::toupper(text[i]);
       }
       return text;
    }

// ---------------------------------------------------------------------------
// Start the main function here
// ---------------------------------------------------------------------------
    int main(){

    // Exercise 1: print the catalogue using a for loop.
    // TODO: loop from 0 to N-1 and print index, name, distance and magnitude.
    for (int i = 0; i <= 7; i++){
        std::cout << i << " " << names[i] << " " << distance[i] << " ly " << " mag " << magnitude[i] << "\n"; 
    }

    // Exercise 2: print the average distance.
    // TODO: call your mean function on the distance array and print the result.
    double average_distance = mean(distance, 8);
    std::cout << average_distance << " Ly" << "\n";

    // Exercise 3: print the nearest and the farthest star (by name).
    // TODO: use your two index functions on the distance array.
    int indexS = indexOfMin(distance, 8);
    int indexL = indexOfMax(distance, 8);

    std::cout << names[indexS] << "\n";
    std::cout << names[indexL] << "\n";

    // Exercise 4: print the brightest star (smallest magnitude).
    // TODO: use your smallest-index function on the magnitude array.
    int indexB = indexBright(magnitude, 8);

    std::cout << names[indexB] << "\n";

    // Exercise 5: measure and index one star name.
    // TODO: print a name's length, its first character and its last character.
    std::string star_name = "Arcturus";
    std::cout << star_name.length() << "\n";
    std::cout << star_name[0] << " " << star_name[star_name.length() - 1] << "\n"; 

    // Exercise 6: build and print a catalogue label for every star.
    // TODO: use string concatenation (+) and std::to_string(...).
    for (int i = 0; i <= 7; i++){
        std::string line = "[" + names[i] + "]" + " " + "distance = " + std::to_string(distance[i]) + " Ly";
        std::cout << line << "\n";
    }

    // Exercise 7: print every star's name in UPPERCASE.
    // TODO: call your capitalising function inside a loop.
    for (int i = 0; i <= 7; i++){
        std::cout << toUpper(names[i]) << "\n";
    }

    // Exercise 8 (challenge): check whether a designation starts with "HD".
    // TODO: test strings like "HD 48915", "HR 2491" and "HD 39801".
    std::string designation[3] = {"HD 48915", "HR 2491", "HD 39801"};
    std::string star = " ";
    for (int i = 0; i <= 2; i++){
        if (designation[i].substr(0,2) == "HD"){
            star = " HD = True";
            std::cout << i << " " << designation[i] << star << "\n";
        } else {
            star = " HD = False";
            std::cout << i << " " << designation[i] << star << "\n";
        }
    }

   return 0;
}

// In my indexOfMin function i originally had for (int i = 0; i <= 7; i++) but for some reason it would not display the name of the closest star when i had it that way, im not so sure why as every other for loop done that way works.
// Uminathi Bandezi 3072728