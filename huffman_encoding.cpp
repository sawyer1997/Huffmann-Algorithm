#include "bits/stdc++.h"
using namespace std;
// Node structure for Huffman Tree
struct MinHeap
{
	char cur;
	int freq;
	MinHeap* left;
	MinHeap* right;
	MinHeap(char cur = '$',int freq = 0)
	{
		left = right = NULL;
		this->cur = cur;
		this->freq = freq;
	}
};
// Comparator function for insertion in Huffman Tree
struct cmp
{
	// As priority_queue is a max heap rather than min-heap,
    // invert the meaning of the < operator,
	// in order to get lower probabilities at the top
	bool operator()(MinHeap *l,MinHeap *r)
	{ return l->freq > r->freq; }
};
map<char, string> code_of_char;
map<string, char> char_from;
priority_queue<MinHeap*, vector<MinHeap*>, cmp> heap;
void Huffman(map<char, int> &frequency)
{
	MinHeap *left,*right,*top;
	for(auto i : frequency)
		heap.push(new MinHeap(i.first,i.second));
	while(heap.size() not_eq 1)
	{
		left = heap.top();
		heap.pop();
		if(heap.size())
		{
			right = heap.top();
			heap.pop();
		}
		else right = NULL;
		top = new MinHeap('$',left->freq + right->freq);
		top->left = left;
		top->right = right;
		heap.push(top);
	}
}
void Encode(MinHeap* node, string code)
{
	if(not node)return;
	if(node->cur != '$')
	{
		code_of_char[node->cur] = code;
		char_from[code] = node->cur;
	}
	Encode(node->left,code+"0");
	Encode(node->right,code+"1");
}
string Decode()
{
	// Now that we've encoded string and now we got to take our string back, so we've their back code as well.
	string till_now = "";
	string decoded_string = "";
	for(char cur : encoded_string)
	{
		till_now += cur;
		if(char_from.find(till_now) != char_from.end())
		{
			decoded_string += char_from[till_now];
			till_now = "";
		}
	}
	return decoded_string;
}
int main()
{
	string given_text;
	cin>>given_text;

	// Storing frequency of every character
	map<char, int> frequency;
	for(char cur : given_text)
		frequency[cur]++;

	// Creating Huffman Tree
	Huffman(frequency);

	// Huffman Tree is ready, now we need to find proper code for each character.
	Encode(heap.top(),"");

	// Till now we've code for every character in string, so we can convert the given string into their following Huffman Code
	string encoded_string = "";
	for(char cur : given_text)
		encoded_string += code_of_char[cur];

	cout<<encoded_string<<endl;
	
// 	Decoded string is finally obtained from the encoded string, which should be same from the given string.
	string decoded_string = Decode();
	cout<<decoded_string<<endl;
	return 0;
}
