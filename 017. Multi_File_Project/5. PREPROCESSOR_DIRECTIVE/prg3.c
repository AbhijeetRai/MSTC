#define DEFINE_NODE(type)   struct node_##type\
                            {\
                                type data;\
                                struct node_##type* prev;\
                                struct node_##type* next;\
                            } 

DEFINE_NODE(int);