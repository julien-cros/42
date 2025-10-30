def all_thing_is_obj(object: any) -> int:
    object_type = type(object)

    match object:
        case list():
            print(f"List : {object_type}")
        case tuple():
            print(f"Tuple : {object_type}")
        case set():
            print(f"Set : {object_type}")
        case dict():
            print(f"Dict : {object_type}")
        case str():
            print(f"{object} is in the kitchen : {object_type}")
        case _:
            print("Type not found")
    return 42
