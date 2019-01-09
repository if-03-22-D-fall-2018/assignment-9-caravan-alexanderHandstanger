/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/

#include <stdlib.h>
#include "caravan.h"
#include "general.h"

struct NodeImplementation{
  PackAnimal animal;
  Node next;
};

struct CaravanImplementation{
  int length;
  Node head;
};

Caravan new_caravan()
{
  Caravan caravan = (Caravan) malloc(sizeof(struct CaravanImplementation));
  caravan->length = 0;
  caravan->head = 0;
  return caravan;
}

int get_length(Caravan caravan)
{
  return caravan->length;
}

void delete_caravan(Caravan caravan)
{
  Node current = caravan->head;
  while(current != 0){
    Node should_delete = current;
    current = current->next;
    sfree(should_delete);
  }
  sfree(caravan);
}

void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(animal == 0){
    return;
  }
  Node current = caravan->head;
  Node to_add = (Node) malloc(sizeof(struct NodeImplementation));
  to_add->animal = animal;
  to_add->next = 0;
  if(caravan->head == 0){
    caravan->head = to_add;
  }
  else{
    while(current->next != 0){
      current = current->next;
    }
    if(current->animal == animal){
      return;
    }
    current->next = to_add;
  }
  add_to_caravan(animal, caravan);
  caravan->length++;
}

void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  Node current = caravan->head;
  Node temp;
  if(animal == 0){
    return;
  }
  if(caravan->head != 0 && caravan->head->animal == animal){
    caravan->head = current->next;
    sfree(current);
    remove_from_caravan(animal, caravan);

    caravan->length--;
  }
}

int get_caravan_load(Caravan caravan)
{
  int loaded = 0;
  Node current = caravan->head;
  while(current != 0){
    loaded+=get_load(current->animal);
    current = current->next;
  }
  return loaded;
}

void unload(Caravan caravan)
{
  Node current = caravan->head;
  while(current != 0){
    unload(current->animal);
    current = current->next;
  }
}

int get_caravan_speed(Caravan caravan)
{
  return 0;
}

void optimize_load(Caravan caravan){

}
