#include "mazemapper.h"

Mazemapper::Mazemapper(string maze)
{
	int row=0;
	int cnt=0;
	int col=0;
	bool error=0;
	int rowsize=0;
	int colsize=maze.find("\n");
	while(cnt<maze.size())
	{
		if(maze[cnt]=='\n')
		{
			row++;
			if(col!=colsize)
			{
				error=1;
				break;
			}
			col=0;
			cnt++;
			continue;
		}
		else if(maze[cnt]=='#')
		{
			cnt++;
			col++;
			continue;
		}
		else if(maze[cnt]!=' ')
		{
			error=1;
			break;
		}
		Vertex *curr=new Vertex;
		curr->r=row;
		curr->c=col;
		int top=-1;
		for(int i=max(0,(int)V.size()-rowsize-1);i<V.size();i++)
		{
			if(V[i]->r==row-1 && V[i]->c==col)
			{
				top=i;
			}
		}
		int left=-1;
		if((int)V.size()-1>=0 && V[V.size()-1]->r==row && V[V.size()-1]->c==col-1)
		{
			left=(int)V.size()-1;
		}
		if(top!=-1)
		{
			curr->neighs.push_back(V[top]);
			V[top]->neighs.push_back(curr);
		}
		 
		if(left!=-1)
		{
			curr->neighs.push_back(V[left]);
			V[left]->neighs.push_back(curr);
		}
		V.push_back(curr);
		col++;
		cnt++;
	}
	
	_height=row;
	_width=colsize;
	if(error)
		_height=-1;
}

bool Mazemapper::valid()
{
	if(_height<1 )
		return false;
	int exits=0;
	for(Vertex* u:V)
	{
		if(u->r==0 || (u->c==_width-1) || u->c==0 || u->r==_height-1){
			exits++;
		}
	}
	if(exits==2)
		return true;
	return false;
}

int Mazemapper::width()
{
	if(!valid())
		return -1;
	return _width;
}

int Mazemapper::height()
{
	if(!valid())
		return -1;
	return _height;
}

bool Mazemapper::solvable()
{
	return true;
}

string Mazemapper::solution(){
	return "";
}