void init(int**** ptr){
    for(int _ = 0; _<2; _++){
        ptr[_] = malloc(sizeof(int**)*2);
        for(int __ = 0; __<2; __++){
            ptr[_][__] = malloc(sizeof(int*)*2);
            for(int ___ = 0; ___<2; ___++){
                ptr[_][__][___] = malloc(sizeof(int)*2);
            }
        }
    }
}
