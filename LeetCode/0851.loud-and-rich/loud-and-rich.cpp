class Solution {
public:
    vector<int> loudAndRich(std::vector<std::vector<int>>& richer,vector<int>& quiet) {
		vector<int> result(quiet.size(), -1);

		unordered_map<int, vector<int>>graph;

		for (const auto& vec : richer) {
			graph[vec[1]].push_back(vec[0]);
		}

		for (int i = 0; i < result.size(); ++i) {
			helper(graph, i, quiet, result);
		}

		return result;

	}


	void helper(unordered_map<int, vector<int>>& graph, int index, const vector<int>& quiet, vector<int>& result) {
		
	    if (result[index] >= 0) {
			return;
		}
		
		result[index] = index;
		for (auto& element_index : graph[index]) {
			helper(graph, element_index, quiet, result);
			
			if (quiet[result[element_index]] < quiet[result[index]]) {
				result[index] = result[element_index];
			}
		}
	}
};