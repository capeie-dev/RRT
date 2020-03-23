#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<ctime>
#include<math.h>
#include<iomanip>
using namespace std;

int depth=0; // to be used to keep node constraint

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
        void print()
        {
            cout<<"Position: "<<pos[0]<<" "<<pos[1];
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

               }


       }

    return nearest;
}

void get_path(vector<vertex> vertices, vector<int> start_pos)
{
    int siz = vertices.size();
    int i = siz-1;
    vector<int> parent = vertices[siz-1].parent;

    while(parent[0]!=start_pos[0] && parent[1]!=start_pos[1])
    {
    for(int x=0;x<siz-1;++x)
        {
        if(vertices[x].pos[0] == parent[0] && vertices[x].pos[1]==parent[1] && x!=i)
          {
                cout<<"\nNode info: \n";
                vertices[x].print();
                cout<<endl;
                parent = vertices[x].parent;
                i=x;

          }


        }
    }

}

int main()
{   //DEFINATIONS
    srand((unsigned) time(0)); // seed for point randomizer

    vector<int> pos = {1,1};
    vector<int> par = {0,0};
    vector<int> goal = {75,85};
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
        //cout<<"newpoint\n"<<newpoint[0]<<" "<<newpoint[1]<<endl;
        vertex add = find_nearest_vertex(vertices,newpoint);
        par = add.pos;
        vertex newnode(newpoint,par);
        vertices.push_back(newnode);
        if(newpoint[0]>goal[0] && newpoint[0]<goal[1])
            {
                if(newpoint[1]>goal[0] && newpoint[1]<goal[1])
                    {
                        goto label;
                    }
            }

    }while(true);
    label:
   /*for(int x=0; x<vertices.size();++x)
       {
           cout<<"Node Info:\n"<<"Parent: "<<vertices[x].parent[0]<<" "<<vertices[x].parent[1]<<endl<<"Pos: "<<vertices[x].pos[0]<<" "<<vertices[x].pos[1]<<endl<<endl;

       }
   */
    //END OF PRINTING THE TREE
    get_path(vertices,pos);
    return 0;

}

