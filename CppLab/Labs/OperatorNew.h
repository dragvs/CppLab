#ifndef CppLab_OperatorNew_h
#define CppLab_OperatorNew_h

class OperatorNew final
{
public:
	static void run();

private:
    OperatorNew();
    OperatorNew(const OperatorNew &);
    OperatorNew &operator=(const OperatorNew &);
};

#endif // CppLab_OperatorNew_h