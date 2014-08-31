#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// random generator
int ngrandom (int i) { return rand() % i; }

int main() {
  srand ( unsigned ( std::time(NULL) ) );

  // initialize vector with student names.
  vector<string> ecen489names;
  ecen489names.push_back("Joseph Binder");
  ecen489names.push_back("Ravi Kiran Boggarapu");
  ecen489names.push_back("Colin Brasher");
  ecen489names.push_back("Nathan Gober");
  ecen489names.push_back("David Grayson");
  ecen489names.push_back("Pravir Singh Gupta");
  ecen489names.push_back("Peng Li");
  ecen489names.push_back("Hong Pan");
  ecen489names.push_back("Panigrahy Sangeeta");
  ecen489names.push_back("Stephen Alexander Polson");
  ecen489names.push_back("Yuanxing Yin");
  ecen489names.push_back("Sheng Zhan");

  // initialize vector with grader names.
  vector<string> ecen489graders;
  ecen489graders = ecen489names;

  // generate a derangement using the rejection method.
  bool derangement = false;
  vector<string>::iterator niterator;
  vector<string>::iterator giterator;

  while (derangement == false) {
    // permute grader names using built-in random generator.
    random_shuffle ( ecen489graders.begin(), ecen489graders.end(), ngrandom);
    // checking that permuation is derangement.
    derangement = true;
    niterator = ecen489names.begin();
    giterator = ecen489graders.begin();
    while ((niterator != ecen489names.end()) && (derangement == true)) {
      if (*niterator == *giterator) {
        derangement = false;
      }
      niterator++;
      giterator++;
    }
  }

  cout << endl;
  giterator = ecen489graders.begin();
  for (string name : ecen489names) {
    cout << *giterator << " will grade work by " << name << endl;
    giterator++;
  }
  cout << endl;

  giterator = ecen489graders.begin();
  for (string name : ecen489names) {
    cout << name << " will be graded by " << *giterator << endl;
    giterator++;
  }
  cout << endl;
}

