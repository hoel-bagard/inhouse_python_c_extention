from inhouse import interval_counter, list_append_1, print_hello_world


def main():
    print("Test script starting")

    print_hello_world()

    sum_res = interval_counter(start:=1, end:=10)
    print(f"The sum of the integers in the interval [{start}, {end}] is: {sum_res}")

    my_list = [3, "2"]
    print(f"List before: {my_list}")
    list_append_1(my_list)
    print(f"List after: {my_list}")
    print("Finished properly")


if __name__ == "__main__":
    main()
