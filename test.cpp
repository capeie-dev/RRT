#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<ctime>
#include<math.h>
#include<iomanip>
using namespace std;

int depth=0; // to be used to keep node constraint
vector<int> parentglobal;
float distance(vector<int> point1, vector<int> point2)
{
	float x = point1[0] - point2[0]; //calculating number to square in next step
	float y = point1[1] - point2[1];
	float dist;

	dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
	dist = sqrt(dist);

	return dist;
}



class vertex{
    public:
        vector<int> parent;
        vector<int> pos;
        int depth;

        vertex(vector<int> pos_arg, vector<int> par_arg)
            {
                pos = pos_arg;
                parent = par_arg;
                if(parent[0]!=0 && parent[0]!=0)
                    {
                        depth = depth+1;
                    }
            }

};

vertex find_nearest_vertex(vector<vertex> vertices, vector<int> newpoint)
{
    int nearest_dist = 10000;
    vertex nearest({0,0},{0,0});
    for(int x=0; x<vertices.size();++x)
       {
            float dist = distance(newpoint, vertices[x].pos);
            if(dist<nearest_dist)
               {
                nearest = vertices[x];
                nearest_dist = dist;
                cout<<dist<<endl;
               }


       }
    ::parentglobal = nearest.parent;
    return nearest;
}


int main()
{   //DEFINATIONS
    srand((unsigned) time(0)); // seed for point randomizer

    vector<int> pos = {1,1};
    vector<int> par = {0,0};
    vector<int> goal = {80,80};
    vertex v(pos,par);

    //tree defination
    vector<vertex> vertices;
    vertices.push_back(v);
    vector<int>  newpoint;
    // statespace boundaries
    int height = 100;
    int width = 100;


    do{

        newpoint = {rand() % height, rand() % width };
        cout<<"newpoint\n"<<newpoint[0]<<" "<<newpoint[1]<<endl;
        vertex add = find_nearest_vertex(vertices,newpoint);
        par = add.pos;
        vertex newnode(newpoint,par);
        vertices.push_back(newnode);
        if(newpoint[0]>75 && newpoint[0]<85)
            {
                if(newpoint[1]>75 && newpoint[1]<85)
                    {
                        goto label;
                    }
            }

    }while(true);
    label:
   for(int x=0; x<vertices.size();++x)
       {
           cout<<vertices[x].pos[0]<<" "<<vertices[x].pos[1]<<endl;

       }
    //RRT IMPLENTATION

    return 0;

}

