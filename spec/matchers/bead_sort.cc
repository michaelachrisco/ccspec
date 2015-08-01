#include<iostream>
#include<vector>

#include <memory>
#include <string>

#include "ccspec/core.h"
#include "ccspec/expectation.h"
#include "ccspec/matchers.h"

using std::string;
using std::shared_ptr;
using ccspec::core::before;
using ccspec::core::context;
using ccspec::core::describe;
using ccspec::core::it;
using ccspec::expect;
using ccspec::matchers::be_falsey;
using ccspec::matchers::be_truthy;
using ccspec::matchers::be;
using ccspec::matchers::eq;


using namespace std;

void distribute_neg( int dist, vector<int> &List)//in theory makes *beads* go down into different buckets.
{
	dist=-dist; //resets to positive number for implamentation

	if (dist > List.size() )
		List.resize(dist,0);

	for (int i=0; i < dist; i++)
		List[i]=List[i]-1;
}
//end of distribute negative

void distribute_pos( int dist, vector<int> &List)//in theory makes *beads* go down into different buckets.
{

	if (dist > List.size() )
		List.resize(dist,0);

	for (int i=0; i < dist; i++)
		List[i]=List[i]+1;
}
//end of distribute positive
vector<int> sort(vector<int> &List){
	int i;
	int zeros=0;
	vector<int> list;
	vector<int> list_pos;
	vector<int> sorted;
	vector<int> sorted_pos;
	for (i=0; i < List.size(); i++)
		if (List[i] < 0)
			distribute_neg (List[i], list);
			else if (List[i] > 0)
				distribute_pos(List[i], list_pos);
				else
					zeros++;

	for (i=0; i < list.size(); i++)
		distribute_neg (list[i], sorted);

	for (i=0; i < list_pos.size(); i++)
		distribute_pos(list_pos[i], sorted_pos);

	//combine two at end.
	//In theory, a list for both positive and negative structures would give better performance at the end, combining the
	//two lists in O(1) time. You may chose to do so if you wish. The same goes with zeros.

	while (zeros > 0)
	{
		sorted_pos.push_back(0);
		zeros--;
	}

	i=sorted.size()-1;
	while (i >= 0) {
		sorted_pos.push_back(sorted[i]);
		i--;
	}

  return sorted_pos;
}


namespace spec {
namespace matchers {
  auto bead_sort = describe("Bead Sort", [] {
    it("sorts a vector", [] {
      int unsorted_arr[] = { -1, -4, -3, 1, 4, 3, 0 };
    	vector<int> to_be_sorted (unsorted_arr, unsorted_arr + sizeof(unsorted_arr) / sizeof(int) );
      int sorted_arr[] = { 4, 3, 1, 0, -1, -3, -4 };
    	vector<int> sorted_vector (sorted_arr, sorted_arr + sizeof(sorted_arr) / sizeof(int) );
      vector<int> c0 = sort(to_be_sorted);

      expect(c0).to(eq(sorted_vector));
    });
  });
}  // namespace matchers
}  // namespace spec
