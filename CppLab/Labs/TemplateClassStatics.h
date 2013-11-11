#ifndef CppLab_TemplateClassStatics_h
#define CppLab_TemplateClassStatics_h

class TemplateClassStatics final
{
public:
	static void run();
	
private:
    TemplateClassStatics();
    TemplateClassStatics(const TemplateClassStatics &);
    TemplateClassStatics &operator=(const TemplateClassStatics &);
};

#endif // CppLab_TemplateClassStatics_h