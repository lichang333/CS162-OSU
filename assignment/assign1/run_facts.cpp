/******************************************************
** Program: run_stats.cpp
** Author: Chang Li
** Date: 04/10/2016
** Description:This program is for read a text file and give the output
** Input: a.out -s (NUM) -f (file.txt),money amount, replay
** Output: 
******************************************************/ 


#include "state_facts.h"

int main(int argc, char *argv[]) {

  int states = atoi(argv[2]);

  ;

  if (argc != 5) {
    cout << "\nWrong input.\nHint:\ntype -s for state;\ntype -f for target "
            "filename;\nEach of number should be greater than "
            "0.\nexample:a.out -s 2 -f states1.txt\n"
         << endl;

    return 1;
  }

  do {
    states = atoi(argv[2]);
    struct state *state_fact;
    int text_count = 0;
    state_fact = new state[states];

    if (argv[1][0] == '-' && argv[1][1] == 's' && argv[3][0] == '-' &&
        argv[3][1] == 'f') {
      fstream tar_file;
      string get_file;
      int NUM_STATES = atoi(argv[2]);

      tar_file.open(argv[4]);
      if (!tar_file) {
        cout << "I cannot find the file.\n";
        return 1;
      }
      string text[255];

      while (!tar_file.eof()) {
        getline(tar_file, get_file);
        text[text_count] = get_file;
        text_count++;
      }
      int state_count = 0;
      int county_count = 0;
      int number = 0;
      for (int i = 0; i < text_count; i++) {
        string temp_arr[12];
        int last_space = 0;
        int word_count = 0;
        for (int j = 0; j < text[i].size(); j++) {
          if (text[i][j] == ' ') {
            temp_arr[word_count] = text[i].substr(last_space, j - last_space);
            word_count++; // scan
            last_space = j + 1;
          }
        }
        temp_arr[word_count] = text[i].substr(last_space, last_space);
        word_count++;

        if (word_count == 3 && !(number == NUM_STATES)) {

          state_fact[state_count].name = temp_arr[0];
          state_fact[state_count].population = atoi(temp_arr[1].c_str());
          state_fact[state_count].counties = (atoi(temp_arr[2].c_str()));
          state_fact[state_count].c =
              new county[state_fact[state_count].counties];
          state_count++;
          number++;
          county_count = 0;

        } else if (word_count > 3) { // use for loop

          state_fact[state_count - 1].c[county_count].name = temp_arr[0];
          state_fact[state_count - 1].c[county_count].population =
              atoi(temp_arr[1].c_str());
          state_fact[state_count - 1].c[county_count].avg_income =
              (float)atof(temp_arr[2].c_str());
          state_fact[state_count - 1].c[county_count].avg_house =
              (float)atof(temp_arr[3].c_str());
          state_fact[state_count - 1].c[county_count].cities =
              atoi(temp_arr[4].c_str());
          state_fact[state_count - 1].c[county_count].city_name =
              new string[state_fact[state_count - 1].c[county_count].cities];
          for (int i = 0;
               i < state_fact[state_count - 1].c[county_count].cities; i++)
            state_fact[state_count - 1].c[county_count].city_name[i] =
                temp_arr[5 + i];

          county_count++;
        } else if (number == NUM_STATES)
          break;

        tar_file.close();
      }
      for (int i = 0; i < NUM_STATES; i++) {
        cout << "State: " << state_fact[i].name << endl << "County: ";
        for (int j = 0; j < state_fact[i].counties; j++)
          cout << state_fact[i].c[j].name << " ";
        cout << endl;
      }

      cout << "\n\nSort State(A-Z): \n";
      sort_a_to_z(state_fact, NUM_STATES);

      cout << "\n\nSort State population: \n";
      sort_lar_pop_state(state_fact, NUM_STATES);

      cout << "\n\nThe county with largest population is: ";
      for (int i = 0; i < NUM_STATES - 1; i++)
        sort_county_largest_pop(state_fact[i].c, state_fact[i].counties);

      cout << "\n\nThe state with largest population is: \n";
      sort_state_largest_pop(state_fact, NUM_STATES);

      cout << "\n\nThe counties sorted(A-Z):\n ";
      for (int i = 0; i < NUM_STATES - 1; i++)
        sort_counties_a_to_z(state_fact[i].c, state_fact[i].counties);

      cout << "\n\nThe counties sorted by population:\n ";
      for (int i = 0; i < NUM_STATES - 1; i++)
        sort_counties_pop(state_fact[i].c, state_fact[i].counties);

      for (int i = 0; i < NUM_STATES - 1; i++)
        fit_county(state_fact, NUM_STATES);

      delete_info(state_fact, NUM_STATES);
    }

    cout << endl;
  
}
while (is_valid_arguments(argv) == true)
  ;

//            for (int k=0;k<word_count;k++){
//                cout<<"word #"<<k<<" : "<<temp_arr[k]<<endl;
//    cout<<"Do you want to input something again?"<<endl;
//    cout << "Please tell me the state and file name: \neg: 2
//    file.txt\n";
//    cin >> states >> argv[4];

return 0;
}
