#ifndef DS_H
#define DS_H

#include<vector>
#include<unordered_map>
namespace DS
{

	struct GraphNode
	{
		std::vector<GraphNode*> mAdjacent{};
	};

	struct Graph
	{
		std::vector<GraphNode*> mNodes{};
	};

	struct WeightedEdge
	{
		struct WeightedGraphNode* mFrom{};
		struct WeightedGraphNode* mTo{};

		float mWeight{};
	};

	struct WeightedGraphNode
	{
		std::vector<WeightedEdge*> mEdges{};
	};

	struct WeightedGraph
	{
		std::vector<WeightedGraphNode*> mNodes{};
	};

	struct GBFSScratch
	{
		const WeightedEdge* mParentEdg{ nullptr };
		float mHeuristic = 0.0f;

		bool mInOpenSet = false;
		bool mInClosedSet = false;
	};

	struct AStarScratch
	{
		const WeightedEdge* mParentEdg{ nullptr };
		float mHeuristic = 0.0f;
		float mActualFromStart{};

		bool mInOpenSet = false;
		bool mInClosedSet = false;
	};

	struct GameState
	{
		enum SquareState{Empty,X,O};
		SquareState mBoard[3][3]{};
	};

	struct GTNode
	{
		std::vector<GTNode*> mChildren{};

		GameState mState{};
	};

	float MaxPlayer(const GTNode* node);
	float MinPlayer(const GTNode* node);

	using NodeToParentMap = std::unordered_map<const GraphNode*, const GraphNode*>;
	using GBFSMap = std::unordered_map<const WeightedGraphNode*, GBFSScratch>;

	bool BFS(const Graph& graph, const GraphNode* Start, const GraphNode* Goal, NodeToParentMap& outMap);

	bool GBFS(const WeightedGraph& g, const WeightedGraphNode* start,
		const WeightedGraphNode* goal, GBFSMap& outMap);

	float ComputeHeuristic(const WeightedGraphNode* a, const WeightedGraphNode* b);

}	
#endif // !DS_H