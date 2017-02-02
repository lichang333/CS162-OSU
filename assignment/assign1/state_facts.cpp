#include "state_facts.h"

void sort_a_to_z(state *s1, int n) {                 //sort state from A-Z
  int *index;
  index = new int[n];
  for (int i = 0; i < n; i++)
    index[i] = i;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      int temp;
      if (s1[index[i]].name > s1[index[j]].name) {
        temp = index[i];
        index[i] = index[j];
        index[j] = temp;
      }
    }
  for (int i = 0; i < n; i++)
    cout << s1[index[i]].name << endl;
  delete[] index;
}

void sort_lar_pop_state(state *s1, int n) {         //sort state population from larggest to smallest 
  int *buffer;
  buffer = new int[n];
  for (int i = 0; i < n; i++)
    buffer[i] = i;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      int temp;
      if (s1[buffer[i]].population > s1[buffer[j]].population) {
        temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
      }
    }
  for (int i = 0; i < n; i++) {
    cout << s1[buffer[i]].name << ": ";
    cout << s1[buffer[i]].population << endl;
  }
  delete[] buffer;
}

void sort_county_largest_pop(county *s1, int n) {               //sort counties population from larggest to smallest
  int *buffer;
  buffer = new int[n];
  for (int i = 0; i < n; i++)
    buffer[i] = i;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int temp;
      if (s1[buffer[i]].population < s1[buffer[j]].population) {
        temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
      }
    }
  for (int i = 0; i < n - n + 1; i++) {
    cout << s1[buffer[i]].name << " :";
    cout << s1[buffer[i]].population << endl;
  }
  delete[] buffer;
}

void sort_state_largest_pop(state *s1, int n) {             //sort larggest state population from larggest to smallest 
  int *buffer;
  buffer = new int[n];
  for (int i = 0; i < n; i++)
    buffer[i] = i;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int temp;
      if (s1[buffer[i]].population < s1[buffer[j]].population) {
        temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
      }
    }
  for (int i = 0; i < n - n + 1; i++) {
    cout << s1[buffer[i]].name << " :";
    cout << s1[buffer[i]].population << endl;
  }
  delete[] buffer;
}

void sort_counties_a_to_z(county *s1, int n) {              //sort counties though  A-Z
  int *index;
  index = new int[n];
  for (int i = 0; i < n; i++)
    index[i] = i;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      int temp;
      if (s1[index[i]].name > s1[index[j]].name) {
        temp = index[i];
        index[i] = index[j];
        index[j] = temp;
      }
    }
  for (int i = 0; i < n; i++)
    cout << s1[index[i]].name << endl;
  delete[] index;
}

void sort_counties_pop(county *s1, int n) {             //sort couties population lar->smal
  int *index;
  index = new int[n];
  for (int i = 0; i < n; i++)
    index[i] = i;
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      int temp;
      if (s1[index[i]].population < s1[index[j]].population) {
        temp = index[i];
        index[i] = index[j];
        index[j] = temp;
      }
    }
  for (int i = 0; i < n; i++)
    cout << s1[index[i]].population << endl;
  delete[] index;
}

void sort_lar_county_pop(county *s1, int n) {           //sort largeest population from counties.
  int *buffer;
  buffer = new int[n];
  for (int i = 0; i < n; i++)
    buffer[i] = i;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) {
      int temp;
      if (s1[buffer[i]].population < s1[buffer[j]].population) {
        temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
      }
    }
  for (int i = 0; i < n - n + 1; i++) {
    cout << s1[buffer[i]].name << " :";
    cout << s1[buffer[i]].population << endl;
  }
  delete[] buffer;
}

void fit_county(state *s1, int n) {                     //counties who are lager than you input.   //what county(ies) is good for you?
  double money;
  cout << "Input a money amout: ";
  cin >> money;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < s1[i].counties; j++) {
      if (s1[i].c[j].avg_house >= money) {
        cout << s1[i].c[j].name << " :";
        cout << s1[i].c[j].avg_house << endl;
      }
    }
  }
}

void get_county_data(state *s, int state_count, int county_count,
                     string *temp_arr) {                            //take data form file to struct county
  s[state_count - 1].c[county_count].name = temp_arr[0];
  s[state_count - 1].c[county_count].population = atoi(temp_arr[1].c_str());
  s[state_count - 1].c[county_count].avg_income =
      (float)atof(temp_arr[2].c_str());
  s[state_count - 1].c[county_count].avg_house =
      (float)atof(temp_arr[3].c_str());
  s[state_count - 1].c[county_count].cities = atoi(temp_arr[4].c_str());
  s[state_count - 1].c[county_count].city_name =
      new string[s[state_count - 1].c[county_count].cities];
  for (int i = 0; i < s[state_count - 1].c[county_count].cities; i++)
    s[state_count - 1].c[county_count].city_name[i] = temp_arr[5 + i];
}

county *create_counties(state *s, int state_count) {            //creat counties
  s[state_count].c = new county[s[state_count].counties];
  return s[state_count].c;
}

void get_state_data(state *s, int state_count, int county_count,
                    string *temp_arr) {                             //get data from file ->  struct state
  s[state_count].name = temp_arr[0];
  s[state_count].population = atoi(temp_arr[1].c_str());
  s[state_count].counties = (atoi(temp_arr[2].c_str()));
  s[state_count].c = create_counties(s, state_count);
}

void delete_info(state *s, int n) {                                     //delete arrays and free memory
  for (int i = 0; i < n; i++)
    for (int j = 0; j < s[i].counties; j++)
      delete[] s[i].c[j].city_name;
  for (int i = 0; i < n; i++)
    delete[] s[i].c;
  delete[] s;
}

state *create_states(int n) {                                           //creat state array
  state *s;
  s = new state[n];
  return s;
}
bool is_valid_arguments(char *info[]) {                                 //check command line
  int x;
  cout << "Do you want to see other number? 1-YES, 0-no." << endl;
  cin >> x;
  if (x == 1) {
    int stats;
    char str[1024];
    cout << "states?" << endl;
    cin >> stats;
    cout << "file?" << endl;
    cin >> str;
    sprintf(info[2], "%d", stats);
    sprintf(info[4], "%s", str);

    return true;
  } else {
    return false;
  }
}

/*for(int k=0;k<state_count;k++){
        cout<<"State#"<<k+1<<": "<<state_fact[k].name<<endl;
        for(int g=0;g<county_count;g++)
                cout<<"counties#"<<k+1<<": "<<state_fact[k].c[g].name<<endl;
}
*/