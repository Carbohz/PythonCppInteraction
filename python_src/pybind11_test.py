import example

if __name__ == "__main__":
    # Sample data for our call:
    x, y = 6, 4

    # answer = example.add(x, y)
    # print(f"    In Python: int: {x} int {y} return val {answer}")

    z = 2
    wrapped_answer = example.wrapped_add(z)
    print(f"Call of wrapped function returns {wrapped_answer}")
