/*
Copyright ESIEE (2009) 

m.couprie@esiee.fr

This software is an image processing library whose purpose is to be
used primarily for research and teaching.

This software is governed by the CeCILL  license under French law and
abiding by the rules of distribution of free software. You can  use, 
modify and/ or redistribute the software under the terms of the CeCILL
license as circulated by CEA, CNRS and INRIA at the following URL
"http://www.cecill.info". 

As a counterpart to the access to the source code and  rights to copy,
modify and redistribute granted by the license, users are provided only
with a limited warranty  and the software's author,  the holder of the
economic rights,  and the successive licensors  have only  limited
liability. 

In this respect, the user's attention is drawn to the risks associated
with loading,  using,  modifying and/or developing or reproducing the
software by the user in light of its specific status of free software,
that may mean  that it is complicated to manipulate,  and  that  also
therefore means  that it is reserved for developers  and  experienced
professionals having in-depth computer knowledge. Users are therefore
encouraged to load and test the software's suitability as regards their
requirements in conditions enabling the security of their systems and/or 
data to be ensured and,  more generally, to use and operate it in the 
same conditions as regards security. 

The fact that you are presently reading this means that you have had
knowledge of the CeCILL license and that you accept its terms.
*/

/* authors : J. Cousty - L. Najman and M. Couprie */

typedef struct JCsoncell
{
  int32_t son;
  struct JCsoncell *next;
} JCsoncell;

typedef struct
{
  int32_t father;            // value -1 indicates the root
  int32_t nbsons;            // value -1 indicates a deleted node
  JCsoncell *sonlist;
  JCsoncell *lastson;
} JCctreenode;

typedef struct
{
  int32_t nbnodes;
  int32_t nbsoncells;
  int32_t root;
  JCctreenode *tabnodes; 
  JCsoncell *tabsoncells;
  uint8_t *flags;
} JCctree;

int32_t saliencyTree(graphe *g, JCctree ** SaliencyTree, double *STaltitude);
int32_t componentTree(graphe *g, JCctree ** CompTree, double *CTaltitude);
void componentTreeFree(JCctree * CT);
int32_t lextinctionvalues(graphe *g, int32_t mode, double *Av, double **Bitmap);
int32_t saliencyTree2(graphe *g,JCctree ** SaliencyTree, double *STaltitude,  int ** pMST); // MST is allocated in the function: free yourself
graphe * MSTToGraph(graphe *g, int * MST, double * weights); // Graphe is allocated: terminate yourself