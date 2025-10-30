import sys
import string


def main(argv):
    try:
        assert len(argv) <= 2, "more than one argument is provided"
        print(type(argv[1]))
        if len(argv) == 2:
            assert type(argv[1]) is str, "argument is not an string"
        print(f"The text contains {len(argv[1])} characters:")
        print(
          f"{sum(1 for index in argv[1] if index.isupper())} upper letters")
        print(
          f"{sum(1 for index in argv[1] if index.islower())} lower letters")
        print(
            f"{sum(1 for index in argv[1] if index in string.punctuation)}"
            "\\ punctuation marks"
        )
        print(
          f"{sum(1 for index in argv[1] if index in string.whitespace)} \
            spaces")
        print(f"{sum(1 for index in argv[1] if index.isnumeric())} digits")

    except AssertionError as err:
        print(f"AssertionError: {err}")
        exit(1)


if __name__ == "__main__":
    main(sys.argv)
