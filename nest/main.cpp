//
//  main.cpp
//  nest
//
//  Created by Ben Campagna on 1/1/20.
//  Copyright © 2020 Ben Campagna. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <sstream>
#include <array>
#include <cmath>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

struct person{
    float gov_dig = 0;
    float connect = 0;
    float pay_bank = 0;
    float mob_econ = 0;
    float dig_social = 0;
    float edu = 0;
    float priv = 0;
    
    float intern = 0;
    float gender = 0;
    float lgbt = 0;
    float environ = 0;
    float mental_health = 0;
    float healthcare = 0;
    float safety = 0;
    float protest = 0;
    
    float esports = 0;
    float concert = 0;
    
    float spirit = 0;
    float spaces = 0;
    float affordabiluty = 0;
    float social_entre = 0;
    float al = 0;
};


struct place{
    string city;
    string country;
    
    float total = 0;
    
    float gov_dig = 0;
    float connect = 0;
    float pay_bank = 0;
    float mob_econ = 0;
    float dig_social = 0;
    float edu = 0;
    float priv = 0;
    
    float intern = 0;
    float gender = 0;
    float lgbt = 0;
    float environ = 0;
    float mental_health = 0;
    float healthcare = 0;
    float safety = 0;
    float protest = 0;
    
    float esports = 0;
    float concert = 0;
    
    float spirit = 0;
    float spaces = 0;
    float affordabiluty = 0;
    float social_entre = 0;
    float al = 0;
};

// Function to run quicksort on an array of integers
// l is the leftmost starting index, which begins at 0
// r is the rightmost starting index, which begins at array length - 1
void quicksort(place world[], int l, int r)
{
    // Base case: No need to sort arrays of length <= 1
    if (l >= r)
    {
        return;
    }
    
    // Choose pivot to be the last element in the subarray
    float pivot = world[r].total;

    // Index indicating the "split" between elements smaller than pivot and
    // elements greater than pivot
    int cnt = l;

    // Traverse through array from l to r
    for (int i = l; i <= r; i++)
    {
        // If an element less than or equal to the pivot is found...
        if (world[i].total <= pivot)
        {
            // Then swap arr[cnt] and arr[i] so that the smaller element arr[i]
            // is to the left of all elements greater than pivot
            place hold = world[i];
            world[i] = world[cnt];
            world[cnt] = world[i];

            // Make sure to increment cnt so we can keep track of what to swap
            // arr[i] with
            cnt++;
        }
    }
    
    // NOTE: cnt is currently at one plus the pivot's index
    // (Hence, the cnt-2 when recursively sorting the left side of pivot)
    quicksort(world, l, cnt-2); // Recursively sort the left side of pivot
    quicksort(world, cnt, r);   // Recursively sort the right side of pivot
}


int main() {
//    cout << setprecision(2);
//    cin >> setprecision(2);//Always show 2 decimal places
    place world[109];
    
    ifstream input("/Users/bencampagna/Desktop/nest/nest/data.txt");
    if (!input) {cout << "error cant open file"; return 1;}
    
    for (int x = 0; x < 108; x++){
        input >> world[x].city >> world[x].country;
        input >> world[x].gov_dig;
        input >> world[x].connect;
        input >> world[x].pay_bank;
        input >> world[x].mob_econ;
        input >> world[x].dig_social;
        input >> world[x].edu;
        input >> world[x].priv;
        input >> world[x].intern;
        input >> world[x].gender;
        input >> world[x].lgbt;
        input >> world[x].environ;
        input >> world[x].mental_health;
        input >> world[x].healthcare;
        input >> world[x].safety;
        input >> world[x].protest;
        input >> world[x].esports;
        input >> world[x].concert;
        input >> world[x].spirit;
        input >> world[x].spaces;
        input >> world[x].affordabiluty;
        input >> world[x].social_entre;
        input >> world[x].al;
    }
    person rates;
    cout << "On a scale of 1 to 10, How important to you is...\n";
    
    cout << "Government Digitalization... \n";
    cin >> rates.gov_dig;
    cout << "Connectivity/5G... \n";
    cin >> rates.connect;
    cout << "Digital Payment & Banking...  \n";
    cin >> rates.pay_bank;
    cout << "Digitalized Mobility/Sharing Economy...  \n";
    cin >> rates.mob_econ;
    cout << "Digitalised Social Habits...  \n";
    cin >> rates.dig_social;
    cout << "Education...  \n";
    cin >> rates.edu;
    cout << "Privacy & Security...  \n";
    cin >> rates.priv;
    cout << "Internationalism...  \n";
    cin >> rates.gov_dig;
    cout << "Gender Equalit...  \n";
    cin >> rates.gender;
    cout << "LGBT+ Equality...  \n";
    cin >> rates.lgbt;
    cout << "Environmental Action...  \n";
    cin >> rates.environ;
    cout << "Access to Mental Health...  \n";
    cin >> rates.mental_health;
    cout << "Access to Healthcare...  \n";
    cin >> rates.healthcare;
    cout << "Safety...  \n";
    cin >> rates.safety;
    cout << "Right to Protest...  \n";
    cin >> rates.protest;
    cout << "ESports...  \n";
    cin >> rates.esports;
    cout << "Concerts...  \n";
    cin >> rates.concert;
    cout << "Entrepreneurial Spirit & Innovation...  \n";
    cin >> rates.spirit;
    cout << "Co-Working Spaces...  \n";
    cin >> rates.spaces;
    cout << "Affordability...  \n";
    cin >> rates.affordabiluty;
    cout << "Social Entrepreneurship... \n";
    cin >> rates.social_entre;
    cout << "AI Industry...  \n";
    cin >> rates.al;
    
    //adjust rates
    //adjust country level
    
    for (int x = 0; x < 108; x++){
        world[x].gov_dig *= rates.gov_dig;
        world[x].connect *= rates.connect;
        world[x].pay_bank *= rates.pay_bank;
        world[x].mob_econ *= rates.mob_econ;
        world[x].dig_social *= rates.dig_social;
        world[x].edu *= rates.edu;
        world[x].priv *= rates.priv;
        world[x].intern *= rates.intern;
        world[x].gender *= rates.gender;
        world[x].lgbt *= rates.lgbt;
        world[x].environ *= rates.environ;
        world[x].mental_health *= rates.mental_health;
        world[x].healthcare *= rates.healthcare;
        world[x].safety *= rates.safety;
        world[x].protest *= rates.protest;
        world[x].esports *= rates.esports;
        world[x].concert *= rates.concert;
        world[x].spirit *= rates.spirit;
        world[x].spaces *= rates.spaces;
        world[x].affordabiluty *= rates.affordabiluty;
        world[x].social_entre *= rates.social_entre;
        world[x].al *= rates.al;
        
        world[x].total = world[x].gov_dig + world[x].connect + world[x].pay_bank + world[x].mob_econ +
                        world[x].dig_social + world[x].edu + world[x].priv + world[x].intern + world[x].gender +
                        world[x].lgbt + world[x].environ + world[x].mental_health + world[x].healthcare +
                        world[x].safety + world[x].protest + world[x].esports + world[x].concert +
                        world[x].spirit + world[x].spaces + world[x].affordabiluty + world[x].social_entre +
                        world[x].al;
        
        //world[x].total /= 22;
    }
    
//    quicksort(world, 0, 108);
    
    
    cout << "RESULTS \n \n -----------------------------------\n";
    for (int x = 0; x < 108; x++){
        cout << x + 1 << ". " << world[x].city << ", " << world[x].country <<" total =  " << world[x].total << "\n";
    }
    
    //calcuate total
    
    //reorder array based on highest total and print
    
    
    
    input.close();
    return 0;
}
