import java.util.*;

public class AdjacencyListGraph extends DirectedGraph {
	protected ArrayList<AdjacencyListVertex> vertices = new ArrayList<AdjacencyListVertex>();
	protected ArrayList<Edge> edges = new ArrayList<Edge>();

	// Creates and adds a new vertex to the graph, provided a vertex with the
	// same label doesn't already exist in the graph. Returns the new vertex on
	// success, null on failure.
	@Override
	public Vertex addVertex(String newVertexLabel) {
		// Your code here (remove placeholder line below)
		if (getVertex(newVertexLabel) == null) {
			AdjacencyListVertex v = new AdjacencyListVertex(newVertexLabel); 
			vertices.add(v);
			return v;
		}
      return null;
	}

	// Adds a directed edge from the first to the second vertex. If the edge
	// already exists in the graph, no change is made and false is returned.
	// Otherwise the new edge is added and true is returned.
	@Override
	public boolean addDirectedEdge(Vertex fromVertex, Vertex toVertex) {
		// Your code here (remove placeholder line below)
		Edge newEdge = new Edge(fromVertex, toVertex);
		for (Edge e : edges) {
			if (e.equalsTo(newEdge)) {
				return false;
			}
		}
      edges.add(newEdge);
	  return true;
	}

	// Returns an ArrayList of edges with the specified fromVertex.
	@Override
	public ArrayList<Edge> getEdgesFrom(Vertex fromVertex) {
		// Your code here (remove placeholder line below)
		ArrayList<Edge> eList = new ArrayList<Edge>();
		for (Edge e : edges) {
			if (e.fromVertex == fromVertex) {
				eList.add(e);
			}
		}
		return eList;
	}

	// Returns an ArrayList of edges with the specified toVertex.
	@Override
	public ArrayList<Edge> getEdgesTo(Vertex toVertex) {
		// Your code here (remove placeholder line below)
		ArrayList<Edge> eList = new ArrayList<Edge>();
		for (Edge e : edges) {
			if (e.toVertex == toVertex) {
				eList.add(e);
			}
		}
		return eList;
	}

	// Returns a vertex with a matching label, or null if no such vertex
	// exists
	@Override
	public Vertex getVertex(String vertexLabel) {
		// Your code here (remove placeholder line below)
		for (Vertex v : vertices) {
			if (v.getLabel().compareTo(vertexLabel) == 0) {
				return v;
			}
		}
      return null;
	}

	// Returns true if this graph has an edge from fromVertex to toVertex
	@Override
	public boolean hasEdge(Vertex fromVertex, Vertex toVertex) {
		// Your code here (remove placeholder line below)
		for (Edge e : edges) {
			if (e.fromVertex == fromVertex && e.toVertex == toVertex) {
				return true;
			}
		}
		return false;
	}
}
