
#ifndef LEXER_UTILS_H
# define LEXER_UTILS_H

# include "structs.h"

void				ft_mutate_lexer_state(t_lexer *lexer);
t_bash_token_map	*ft_get_token_map(void);
bool				ft_is_valid_symbol(char c);

#endif /* LEXER_UTILS_H */