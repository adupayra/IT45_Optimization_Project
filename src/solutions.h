#ifndef DEF_SOLUTIONS
#define DEF_SOLUTIONS

#include "constants.h"
#include "interface.h"


typedef struct
{
	Interface interface[NBR_INTERFACES];
	double avg_distance;
	double standard_error;
	double fcorr;
	double z;
	int penalties;
} Solution;

typedef struct node
{
	struct node *leftchild;
	struct node *rightchild;
	Solution *solution;
} Node;

typedef Node *Arbre;
 
void create_from_solution(Solution **, Solution);

int get_champs_formation(int, int);

void solve();

void croiser(Solution *, Solution *, Solution *, int, int);

void add_creneau_croiser(Interface **, int, IntegerArray *, int, int);

void find_init_solution(Solution *);

void improve_solution(Arbre *, int);

void improve_standard_error(Solution*);

void improve_penalties(Solution *);

void find_best_solution(Solution *, Solution *, int);

void update_solution(Solution *);

double compute_distance(double, double, double, double);

void compute_distances_interfaces(Solution *);

double compute_avg_distance(Solution);

double compute_standard_error(Solution*, double);

double compute_fcorr(double);

int compute_penalties(Solution*);

double compute_min_z(double avg, double std, double fcorr, double penalty);

void print_formation();

void print_z(Solution);

void print_interfaces(Interface*);

void print_solution(Solution);

void print_distances();

void delete_solution(Solution *);

void delete_solution_intarrays(Interface *);

#endif
