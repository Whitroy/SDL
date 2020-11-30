#include "DS.h"
#include <queue>

namespace DS
{
    float MaxPlayer(const GTNode* node)
    {
        if (node->mChildren.empty())
        {
            return GetScore(node->mState);
        }
        
        float maxValue = -std::numeric_limits<float>::infinity();

        for (const GTNode* child : node->mChildren)
        {
            maxValue = std::max(maxValue, MinPlayer(child));
        }

        return maxValue;
    }

    float MinPlayer(const GTNode* node)
    {
        if (node->mChildren.empty())
        {
            return GetScore(node->mState);
        }

        float minValue = std::numeric_limits<float>::infinity();

        for (const GTNode* child : node->mChildren)
        {
            minValue = std::min(minValue, MaxPlayer(child));
        }

        return minValue;
    }

    const GTNode* MinimaxDecide(const GTNode* root)
    {
        // Find the subtree with the maximum value, and save the choice
        const GTNode* choice = nullptr;
        float maxValue = -std::numeric_limits<float>::infinity();
        for (const GTNode* child : root->mChildren)
        {
            float v = MinPlayer(child);
            if (v > maxValue)
            {
                maxValue = v;
                choice = child;
            }
        }
        return choice;
    }


    float GetScore(GameState state)
    {
        return 0.0f;
    }

    bool DS::BFS(const Graph& graph, const GraphNode* Start, const GraphNode* Goal, NodeToParentMap& outMap)
    {
        bool pathFound{ false };

        std::queue<const GraphNode*> q{};

        q.emplace(Start);

        while (!q.empty())
        {
            const GraphNode* current = q.front();
            q.pop();

            if (current == Goal)
            {
                pathFound = true;
                break;
            }

            for (const GraphNode* neighbor : current->mAdjacent)
            {
                const GraphNode* parent = outMap[neighbor];

                if (parent == nullptr && neighbor != Start)
                {
                    outMap[neighbor] = current;
                    q.emplace(neighbor);
                }
            }
        }
        return pathFound;
    }
    bool GBFS(const WeightedGraph& g, const WeightedGraphNode* start, const WeightedGraphNode* goal, GBFSMap& outMap)
    {
        std::vector<const WeightedGraphNode*> OpenSet{};

        const WeightedGraphNode* current = start;

        outMap[current].mInClosedSet = true;

        do
        {
            for (const WeightedEdge* edge : current->mEdges)
            {
                GBFSScratch& data = outMap[edge->mTo];

                if (!data.mInClosedSet)
                {
                    data.mParentEdg = edge;

                    if (!data.mInOpenSet)
                    {
                        data.mHeuristic = ComputeHeuristic(edge->mTo, goal);

                        data.mInOpenSet = true;

                        OpenSet.emplace_back(edge->mTo);
                    }
                }
            }

            if (OpenSet.empty())
                break;

            auto iter = std::min_element(OpenSet.begin(), OpenSet.end(),
                [&outMap](const WeightedGraphNode* a, const WeightedGraphNode* b)
            {
                    return outMap[a].mHeuristic < outMap[b].mHeuristic;
            });

            current = *iter;

            OpenSet.erase(iter);

            outMap[current].mInOpenSet = false;

            outMap[current].mInClosedSet = true;

        } while (current != goal);

        return (current == goal)? true:false;
    }
    float ComputeHeuristic(const WeightedGraphNode* a, const WeightedGraphNode* b)
    {

        return 0.0f;
    }
}
