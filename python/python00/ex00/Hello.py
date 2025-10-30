ft_list = ["Hello", "tata!"]
ft_tuple = ("Hello", "toto!")
ft_set = {"Hello", "tutu!"}
ft_dict = {"Hello": "titi!"}


def case_modifier(ft_name):
    match ft_name:
        case "ft_list":
            ft_list[1] = "World!"
        case "ft_tuple":
            global ft_tuple
            buffer = list(ft_tuple)
            buffer[1] = "France!"
            ft_tuple = tuple(buffer)
        case "ft_set":
            ft_set.remove("tutu!")
            ft_set.add("Paris!")
        case "ft_dict":
            ft_dict["Hello"] = "42Paris!"


case_modifier("ft_list")
case_modifier("ft_tuple")
case_modifier("ft_set")
case_modifier("ft_dict")

print(ft_list)
print(ft_tuple)
print(ft_set)
print(ft_dict)

["Hello", "World!"]
("Hello", "France!")
{"Hello", "Paris!"}
{"Hello": "42Paris!"}
