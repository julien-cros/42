def NULL_not_found(object: any) -> int:
    object_type = type(object)

    match object: 
        case None:
            print(f"Nothing: {object} {object_type}")
        case float() if object != object:
            print(f"Cheese: {object} {object_type}")
        case int() if object == 0:
            print(f"Zero: {object} {object_type}")
        case str() if not object:
            print(f"Empty: {object} {object_type}")
        case bool() if object is False:
            print(f"Fake: {object} {object_type}")
        case _:
            print("Type not Found")
            return 1
    return 0
