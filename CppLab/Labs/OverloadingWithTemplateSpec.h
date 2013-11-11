#ifndef CppLab_OverloadingWithTemplateSpec_h
#define CppLab_OverloadingWithTemplateSpec_h

class OverloadingWithTemplateSpec final
{
public:
	static void run();

private:
    OverloadingWithTemplateSpec();
    OverloadingWithTemplateSpec(const OverloadingWithTemplateSpec &);
    OverloadingWithTemplateSpec &operator=(const OverloadingWithTemplateSpec &);
};

#endif // CppLab_OverloadingWithTemplateSpec_h