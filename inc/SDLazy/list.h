#ifndef			LIST_H
# define		LIST_H

typedef	struct s_link	t_link;
typedef	struct s_list	t_list;

struct			s_link
{
  t_list*		list;
  t_link*		prev;
  t_link*		next;
  void*			data;
};

struct			s_list
{
  t_link*		first;
  t_link*		last;
  unsigned		length;
};

void			list_init(t_list*);
void			list_destroy(t_list*);

void			list_print(t_list*);
void			list_print_rev(t_list*);

int			list_push_front(t_list*, void* data);
int			list_push_back(t_list*, void* data);

void			list_pop_front(t_list*);
void			list_pop_back(t_list*);
void			list_pop_at(t_link*);

unsigned		list_find_n_destroy(t_list*, void* data);
t_link*			list_find_data(t_list*, void* data);

void			list_foreach(t_list*, void (*f)());

#endif
