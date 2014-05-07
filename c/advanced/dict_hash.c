
//==============================================================================
//============================== HASH TABLE ====================================
//==============================================================================

typedef struct _node{
  char *name;
  int desc;
  struct _node *next;
}node_s;

#define HASHSIZE 501
static node_s* hashtab[HASHSIZE];

void inithashtab(){
  int i;
  for(i=0;i<HASHSIZE;i++)
    hashtab[i]=NULL;
}

unsigned int hash(char *s){
  unsigned int h=0;
  for(;*s;s++)
    h = *s + h * 31;
  return h%HASHSIZE;
}
unsigned int joaat_hash(char *key){
    unsigned int hash = 0;   //uint32
    size_t i;
    for (i=0; *key ; key++,i++){
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
    //avalanch effect
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    return hash;
}
node_s* lookup(char *n){
  unsigned int hi=hash(n);
  node_s* np=hashtab[hi];
  for(;np!=NULL;np=np->next){
    if(!strcmp(np->name,n))
      return np;
  }

  return NULL;
}

int get(char* name){
    node_s* n=lookup(name);
    if(n==NULL)
        return -1;
    return n->desc;
}

int install(char* name,int desc){
  unsigned int hi;
  node_s* np;
  if((np=lookup(name))==NULL){
    hi=hash(name);
    np=(node_s*)malloc(sizeof(node_s));
    if(np==NULL)
      return 0;
    np->name=strdup(name);
    if(np->name==NULL) return 0;
    np->next=hashtab[hi];
    hashtab[hi]=np;
  }
  np->desc=desc;
  return 1;
}

/* A pretty useless but good debugging function,
   which simply displays the hashtable in (key.value) pairs
*/
void displaytable(){
  int i;
  node_s *t;
  for(i=0;i<HASHSIZE;i++){
    if(hashtab[i]==NULL)
      printf("() ");
    else{
      t=hashtab[i];
      printf("(");
      for(;t!=NULL;t=t->next)
        printf(" -(%s.%d) ",t->name,t->desc);
      printf(")");
    }
  }
}

void cleanup(){
  int i;
  node_s *np,*t;
  for(i=0;i<HASHSIZE;i++){
    if(hashtab[i]!=NULL){
      np=hashtab[i];
      while(np!=NULL){
        t=np->next;
        free(np->name);
        //free(np->desc);
        free(np);
        np=t;
      }
    }
  }
}

