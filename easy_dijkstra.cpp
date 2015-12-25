#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <functional>
#include<time.h>

using namespace std;


struct Vertex;

// Structure stored in priority queue for Dijkstra's algorithm.
struct Path
{
    Vertex *dest;   // w
    unsigned int  cost;   // d(w)
	unsigned int  weight;

    Path( Vertex *d = 0, double c = 0, double w = 0 )
      : dest( d ), cost( c ), weight (w) { }

    bool operator> ( const Path & rhs ) const
      { return cost > rhs.cost; }
    bool operator< ( const Path & rhs ) const
      { return cost < rhs.cost; }


};

static const int INFINITY = INT_MAX;

// Basic info for each vertex.
struct Vertex
{
    string		  name;
	vector<Path>  adj;     // Adjacent vertices
    unsigned int  dist; 
    Vertex       *prev;    // Previous vertex on shortest path
    bool           visited; // vesited?

    Vertex( const string & nm ) : name( nm )
      { reset( ); };

    void reset( )
      { dist = INFINITY; prev = NULL; visited = false; }


};

class Graph
{
  public:
    Graph( ) { }
    ~Graph( );
    void addEdge( const string & sourceName, const string & destName, unsigned int cost );
    unsigned int dijkstra();

  private:
	Vertex * getVertex( const string & vertexName );
    void clearAll( );

    typedef map<string,Vertex *,less<string> > vmap;

      // Copy semantics are disabled; these make no sense.
    Graph( const Graph & rhs ) { }
    const Graph & operator= ( const Graph & rhs )
      { return *this; }

    vmap vertexMap;
};


// Add a new edge to the graph.
void Graph::addEdge( const string & sourceName, const string & destName, unsigned int weight )
{
    Vertex * v = getVertex( sourceName );
    Vertex * w = getVertex( destName );
    v->adj.push_back( Path( w, 0, weight ) );
	w->adj.push_back( Path( v, 0, weight ) );	// undirected edge

}

Vertex * Graph::getVertex( const string & vertexName )
{
    vmap::iterator itr = vertexMap.find( vertexName );

    if( itr == vertexMap.end( ) )
    {
        Vertex *newv = new Vertex( vertexName );
        vertexMap[ vertexName ] = newv;
        return newv;
    }
    return (*itr).second;
}

void Graph::clearAll( )
{
    for( vmap::iterator itr = vertexMap.begin( ); itr != vertexMap.end( ); ++itr )
        (*itr).second->reset( );
}

// Destructor: cleans up the Vertex structs.
Graph::~Graph( )
{
    for( vmap::iterator itr = vertexMap.begin( ); itr != vertexMap.end( ); ++itr )
        delete (*itr).second;
}

unsigned int Graph::dijkstra()
{	unsigned int length=0;
	priority_queue<Path, vector<Path>, greater<Path> > pq;
    Path vrec;     // Stores the result of a deleteMin

    vmap::iterator itr = vertexMap.find("0");


    clearAll( );

    Vertex *start = (*itr).second;
    pq.push( Path( start, 0, 0 ) ); start->dist = 0;

    for( int nodesSeen = 0; nodesSeen < vertexMap.size( ); nodesSeen++ )
    {
        do    // Find an unvisited vertex
        {
            if( pq.empty( ) )
                return length;
            vrec = pq.top( ); pq.pop( );
			
        } while( vrec.dest->visited );
		length += vrec.cost;

        Vertex *v = vrec.dest;
        v->visited = true;

        for( int i = 0; i < v->adj.size( ); i++ )
        {
            Path e = v->adj[ i ];
            Vertex *w = e.dest;
            unsigned int cvw = e.weight;
            if( w->dist > v->dist + cvw )
            {
                w->dist = v->dist + cvw;
                w->prev = v;
                pq.push( Path( w, w->dist, cvw ) );
            }
        }
    };
	return length;
}

int main()
{
	time_t start_time, cur_time;
	Graph g;
	string filename,temp, source, dest;
	unsigned int weight;
	char ch;
		cout << "Enter file name :";
		cin >> filename;
		cout << "reading :" << filename << "\n";
		ifstream textfile(filename.c_str());
		getline(textfile,temp);
		while (!textfile.eof()){
			getline(textfile,source);
			if (source != "\0"){
				while (textfile.peek() !='\n'){
					textfile >> dest;
					textfile >> weight;
					g.addEdge( source, dest, weight );
					textfile.get(ch);
				};
				getline(textfile,temp);
			};
		};
		textfile.close();
		cout << filename << " read\n";
		cout << "running djikstra algorithm " << "\n";
		time(&start_time);
		cout << "total length = " << g.dijkstra() << "\n";
		time(&cur_time);
		cout << "time: " << cur_time - start_time << " sec" << "\n";
		cout << "Program finished!";

	return 0;
}