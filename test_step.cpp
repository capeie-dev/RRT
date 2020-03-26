#include<iostream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<ctime>
#include<math.h>
#include<iomanip>
#include<fstream>
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

void get_path(vector<vertex> vertices, vector<int> start_pos, vector<int> goal_pos, int step_size)
{   ofstream outfile;
    outfile.open("path.txt",ios::trunc);
    int siz = vertices.size();
    int i = siz-1;
    vector<int> parent = vertices[siz-1].parent;
    vector<int> temp = goal_pos;
    outfile<<goal_pos[0]<<" "<<goal_pos[1]<<endl;


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
                        outfile<<vertices[x].pos[0]<<" "<<vertices[x].pos[1]<<endl;

                        }
                }
        }
		cout<<"\nNode info: \n";
        cout<<"Postion: "<<start_pos[0]<<" "<<start_pos[1];
        outfile<<start_pos[0]<<" "<<start_pos[1]<<endl;
        outfile.close();

}

void print_all_nodes(vector<vertex> vertices)
{
        for(int x=0;x<vertices.size();++x)
           {
             cout<<"\n\nNode info:\n";
             vertices[x].print();
             cout<<endl;
             cout<<"Parent: "<<vertices[x].parent[0]<<" "<<vertices[x].parent[1]<<endl;
           }
}

void write_file(vector<vertex> vertices, vector<int> start_pos, vector<int> goal)
{
    ofstream outfile;
    outfile.open("all_nodes.txt",ios::trunc);

    for(int x=0;x<vertices.size();++x)
        outfile<<vertices[x].pos[0]<<" "<<vertices[x].pos[1]<<endl;
    outfile<<start_pos[0]<<" "<<start_pos[1]<<endl;
    outfile<<goal[0]<<" "<<goal[1]<<endl;
    outfile.close();

}



int main()
{   //DEFINATIONS
    ofstream out_obstacles;

    ofstream out_endpoints;
    out_endpoints.open("endpoints.txt",ios::trunc);

    srand((unsigned) time(0)); // seed for point randomizer
    vector<int> pos = {0,0};
    vector<int> par = {0,0};
    vector<int> goal = {0,0}; // goal region preset
    int step_size;
    int num_obs;
    int obs[num_obs][2];
    cout<<"The 2D world is 100x100 square\n\n";
    cout<<"Enter initial x_pos: ";
    cin>>pos[0];
    cout<<"Enter intial y_pos: ";
    cin>>pos[1];
    cout<<"Enter goal x_pos: ";
    cin>>goal[0];
    cout<<"Enter goal y_pos: ";
    cin>>goal[1];


    out_endpoints<<pos[0]<<" "<<pos[1]<<endl<<goal[0]<<" "<<goal[1];
    out_endpoints.close();
    //Add obstacles
    char choice;
    cout<<"Add obstacles?[Y/N]: ";
    cin>>choice;
    if(choice=='y')
    {
    cout<<"Enter the number of obstacles: ";
    cin>>num_obs;
    out_obstacles.open("obstacles.txt",ios::trunc);
    for(int con=0;con<num_obs;++con)
        {

            cout<<"\nEnter centroid of obstacle "<<con+1<<": "<<endl;
            cout<<"Enter x_pos: ";
            cin>>obs[con][0];
            cout<<"Enter y_pos: ";
            cin>>obs[con][1];
            out_obstacles<<obs[con][0]<<" "<<obs[con][1]<<endl;



        }
        out_obstacles.close();
     }



    //initialize vertex tree
    vertex v(pos,par);

    //tree defination
    vector<vertex> vertices;
    vertices.push_back(v);

    //randompoint storage
    vector<int>  newpoint;

    // statespace boundaries
    int height = 100;
    int width = 100;

    //RRT implementation
    bool done = true;
    do{

        newpoint = {rand() % height, rand() % width };
        vertex add = find_nearest_vertex(vertices,newpoint);

        //checks step size

        par = add.pos;
        vertex newnode(newpoint,par);
        vertices.push_back(newnode);
        //checks if the point lies within collision of the obstacle
        if(choice=='y')
        {
            for(int cont=0; cont<num_obs;++cont)
            {
            if(newpoint[0]>obs[cont][0]+10 && newpoint[0]<obs[cont][0]-10)
               {
                    if(newpoint[1]>obs[cont][1]+10 && newpoint[1]<obs[cont][1]-10)
                        goto label;
               }
            }
        }
        //checks if the point lies within the collision of the goal point
        if(newpoint[0]>goal[0]-10 && newpoint[0]<goal[0]+10)
           {
               if(newpoint[1]>goal[1]-10 && newpoint[1]<goal[1]+10)
                   {
                       done = false;
                   }
           }
        label:
            cout<<"";

        }while(done);


    write_file(vertices, pos, goal);  //unomment this write all the veritces to a text file
    //print_all_nodes(vertices); //uncomment this to view all the vertices
    get_path(vertices,pos, goal,step_size);
    return 0;

}


