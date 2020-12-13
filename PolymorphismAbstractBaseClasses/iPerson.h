#pragma once
#ifndef  SDDS_IPERSON_H_
#define SDDS_IPERSON_H_

#include <iostream>
namespace sdds
{
	class iPerson
	{
	public:
		virtual void display(std::ostream&) const = 0;
	};

	iPerson* CreatePerson();
}
#endif //!SDDS_IPERSON_H_
