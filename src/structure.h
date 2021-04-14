/*
Auteur : Mascaro Valentin , Vidal Mazuy Antoine
Version : 0.3
Date derniere modif : 14/04/2021
*/

#ifndef _STRUCTURE_H
#define _STRUCTURE_H


// /*================================STRUCTURES===================================*/
// /*
// 	Structure contenant tous les symbols réservé
// 	pour chaque bloc.
// */
// typedef struct _symbol {
// 	char* var;
// 	struct _expression valeur;
// 	struct _symbol suivant_t;
// } symbol;

// /*
// 	Structure des blocs, le programme est un bloc, la fonction est un bloc etc..
// 	Chaque bloc contient les symboles du précédent bloc (parent).
// 	A la création d'un bloc, on copie le bloc actuel dans le nouveau.
// */
// typedef struct _bloc {
// 	struct _symbol *symbol_t;
// 	struct _instruction *instruction_t;
// 	struct _bloc *bloc_t;
// } bloc;

typedef struct _expression {
	char* node;
	struct _expression *expr1_t;
	struct _expression *expr2_t;
} expression;

// /* ============================= INSTRUCTIONS =================================*/

// /*
// 	Structure des instructions, contient la strucuture adaptée selon l'énum.
// */
// enum instruction_e{ITER,SELECT,SAUT,AFFECT,APPEL};

// typedef struct _instruction{ 
// 	struct _expression *expression_t;
// 	enum instruction_e *type_instruct_t;

// 	struct _selection selection_t
// 	struct _instruction suivant;
// } instruction;

// 	enum iteration_e{FOR,WHILE};

// 	typedef struct _iteration {
// 		struct _symbol *symbol_t;
// 		enum iteration_e *type_iteration_t;
		
// 		struct _for *for_t;
// 		struct _while *while_t;
// 	} iteration;
// 		/*
// 			affectation_t condition_t increment instruction_t jamais vide
			
// 		*/
// 		typedef struct _for{
// 			struct _affectation *affectation_t;
// 			//struct _condition condition_t;
// 			struct _affectation *increment_t;
// 			struct _instruction *instruction_t;
// 		} for;

// 		/*
// 			Iteration de type While 
// 		*/
// 		typedef struct _while{	
// 			//struct _condition condition_t;
// 			struct _instruction *instruction_t;
// 		}while;

// 	//enum if/switch/constante/default
// 	typedef struct _selection{
// 		//
// 	} selection;
// 		//if

// 		//etc

// 	/* 
// 		return et break
// 		expression potentiellement null
// 	*/
// 	typedef struct _saut {
// 		struct _expression *expression_t; 
// 	} saut;

// 	/*
		
// 	*/
// 	typedef struct _affectation {
// 		struct _symbol *symbol_t;
// 		struct _expression *expression_t;
// 	} affectation;

// 	/*
// 		Appel de fonction, 
// 	*/
// 	typedef struct _appel {
// 		// TODO
// 	} appel;


// /*======================================FONCTIONS=============================*/

// //*bloc function(parameter)
// bloc *init_program(); // créé le premier bloc

// bloc *new_bloc(*bloc_t); // créé un bloc a partir de l'actuel

// void add_symbol(*bloc_t, char* var); // declaration d'une variable

// void add_value(*bloc_t, char* var, struct _expression valeur); // associe la valeur à un symbole.

// symbol *query(char* nomVar); // cherche une variable avec ce nom, si retour null 
// 							 // -> la variable n'existe pas
								



#endif
