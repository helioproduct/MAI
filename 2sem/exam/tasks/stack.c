// Вариант 7
// Псевдокод. Сортиорвка стека слиянием

void reverse(Stack *s)
{
    Stack *b;
    create(b);
    while (!isEmpty(a)) {
        push(b, pop(a));
    }
    copy(b, a);
}

stack *merge(stack *a, stack*b)
{
    stack *res;
    while (!isEmpty(a) && !isEmpty(b))
    {
        if (top(a) < top(b)) {
            push(res, pop(a);)
        } else {
            push(res, pop(b));
        }
    }
    while (!isEmpty(a))
        push(res, pop(b));
    while (!isEmpty(b))
        push(res, pop(b));
    

    reverse(res);
    return res;
}


void merge_sort(stack **x)
{
    int l;
    stack *a;
    stack *b;
    if (size(*x) > 1) {
        l = size(*x) / 2; 
    }

    create(a);
    crate(b);

    for (int i = 0; i < l; i++) {
        push(a, pop(*x));
    }

    while (!isEmpty(*x)) {
        push(b, pop(*x));
    }

    merge_sort(a);
    merge_sort(b);

    *x = merge(a, b);
}