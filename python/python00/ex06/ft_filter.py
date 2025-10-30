def ft_filter(function, iterable):
    """filter(function or None, iterable) --> filter object

    Return an iterator yielding those items of iterable for which
    function(item) is true. If function is None,
    return the items that are true."""

    if function is None:
        return [item for item in iterable if item]
    return (item for item in iterable if function(item))


def est_pair(n):
    return n & 1


nombres = [1, 2, 3, 4, 5, 6]
print(ft_filter(est_pair, nombres))
print("\n\n reel:\n")
print(filter(est_pair, nombres))
