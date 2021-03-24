#include"extraFunctions.h"
#include <fstream>
using namespace std;

void Quicksort_midpoint(vector<string>&v, int i, int k);
int Partition(vector<string>&v, int i, int k);//ised bu quicksort_midpoint

int main(){
	srand(time(0));
	char g;
	do{
	output(generateName(), false);
		cin.get(g);
	}while(g != 'n');
// 	vector<string> v;
	ifstream ifs("dictionarylist.txt");
// 	string line;
// 	cout << "Loading: " << endl;
// 	while(getline(ifs, line)){
// 		v.push_back(line);
// 	}
// 	
// 	/ofstream ofs("sortedNamesList.txt");
// 	for(unsigned i = 0; i < newV.size(); ++i){
// 		ofs << newV.at(i) << endl;
// 	}
// 	cout << "Done: " << endl;
	return 0;
}


void Quicksort_midpoint(vector<string>&v, int i, int k){
	int j = 0;
   
   // Base case: If there are 1 or zero elements to sort,
   // partition is already sorted
   if (i >= k) {
      return;
   }
   
   // Partition the data within the array. Value j returned
   // from partitioning is location of last element in low partition.
   j = Partition(v, i, k);
   
   // Recursively sort low partition (i to j) and
   // high partition (j + 1 to k)
   Quicksort_midpoint(v, i, j);
   Quicksort_midpoint(v, j + 1, k);
}

int Partition(vector<string>&v, int i, int k) {
   int l = 0;
   int h = 0;
   int midpoint = 0;
   string pivot;
   string temp;
   bool done = false;
   
   // Pick middle element as pivot
   midpoint = i + (k - i) / 2;
   pivot = v.at(midpoint);
   
   l = i;
   h = k;
   
   while (!done) {
      
      // Increment l while numbers[l] < pivot
      while (v.at(l) < pivot) {
         ++l;
      }
      
      // Decrement h while pivot < numbers[h]
      while (pivot < v.at(h)) {
         --h;
      }
      
      // If there are zero or one elements remaining,
      // all numbers are partitioned. Return h
      if (l >= h) {
         done = true;
      }
      else {
         // Swap numbers[l] and numbers[h],
         // update l and h
         temp = v.at(l);
         v.at(l) = v.at(h);
         v.at(h) = temp;
         
         ++l;
         --h;
      }
   }
   
   return h;
}
