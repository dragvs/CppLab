#ifndef CppLab_PrivateMemberAccess_h
#define CppLab_PrivateMemberAccess_h

class PrivateMemberAccess final
{
public:

	static void run();
	
private:
	PrivateMemberAccess();
	PrivateMemberAccess(const PrivateMemberAccess &);
    PrivateMemberAccess &operator=(const PrivateMemberAccess &);
};

#endif // CppLab_PrivateMemberAccess_h