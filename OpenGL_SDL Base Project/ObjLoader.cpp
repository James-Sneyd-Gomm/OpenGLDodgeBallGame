#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Commons.h"
#include "ObjLoader.h"
#include <sys\stat.h>

using namespace std;

long length(int f)
{
	struct stat buf;
	fstat(f, &buf);
	return(buf.st_size);
}


char LoadOBJ(obj_type_ptrObj p_object, char *filename)
{
	int i = 0;
	int j = 0;
	int k = 0;	
	int l = 0;
	FILE* inFile;


	inFile = fopen(filename, "r");

	while (1)
	{
		char buf[256];
		int line = fscanf(inFile, "%s", buf);
		if (line == EOF)
		{
			break;
		}

		//if (strcmp(buf, "#") == 0)
		//{
		//	break;
		//}

		if (strcmp(buf, "v") == 0)
		{
			fscanf(inFile, "%f %f %f\n",
				&p_object->vertex[i].x,
				&p_object->vertex[i].y,
				&p_object->vertex[i].z);
			i++;
		}

		if (strcmp(buf, "vt") == 0)
		{
			fscanf(inFile, "%f %f",
				&p_object->mapcoord[j].u,
				&p_object->mapcoord[j].v);
			j++;
		}

		if (strcmp(buf, "vn") == 0)
		{
			fscanf(inFile, "%f %f %f\n",
				&p_object->normal[k].x,
				&p_object->normal[k].y,
				&p_object->normal[k].z);
			k++;
		}

		if (strcmp(buf, "f") == 0)
		{
			fscanf(inFile, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
				&p_object->indVert[l].a,
				&p_object->indTex[l].a,
				&p_object->indNorm[l].a,
				&p_object->indVert[l].b,
				&p_object->indTex[l].b,
				&p_object->indNorm[l].b,
				&p_object->indVert[l].c,
				&p_object->indTex[l].c,
				&p_object->indNorm[l].c);
				l++;

		}



	}
	p_object->vertices_qty = i;
	p_object->polygons_qty = l;

	fclose(inFile);
	return(1);

}