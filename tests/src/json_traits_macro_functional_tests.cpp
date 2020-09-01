// Copyright 2020 Daniel Parker
// Distributed under Boost license

#if defined(_MSC_VER)
#include "windows.h" // test no inadvertant macro expansions
#endif
#include <jsoncons/json.hpp>
#include <jsoncons/json_encoder.hpp>
#include <catch/catch.hpp>
#include <sstream>
#include <vector>
#include <utility>
#include <ctime>
#include <cstdint>
#include <jsoncons/json.hpp>

namespace {
namespace ns {

    class Employee_NMN
    {
    public:
        std::string name_;
        std::string surname_;

        Employee_NMN() = default;

        Employee_NMN(const std::string& name, const std::string& surname)
            : name_(name), surname_(surname)
        {
        }

        friend bool operator<(const Employee_NMN& lhs, const Employee_NMN& rhs)
        {
            if (lhs.surname_ < rhs.surname_)
                return true;
            return lhs.name_ < rhs.name_;
        }
    };

    class Company_NMN 
    {
    public:
        std::string name_;
        std::vector<uint64_t> employeeIds_;
        jsoncons::optional<double> rating_;

        Company_NMN() = default;

        Company_NMN(const std::string& name, const std::vector<uint64_t>& employeeIds)
            : name_(name), employeeIds_(employeeIds), rating_()
        {
        }
    };

    class Employee_AMN
    {
    public:
        std::string name_;
        std::string surname_;

        Employee_AMN() = default;

        Employee_AMN(const std::string& name, const std::string& surname)
            : name_(name), surname_(surname)
        {
        }

        friend bool operator<(const Employee_AMN& lhs, const Employee_AMN& rhs)
        {
            if (lhs.surname_ < rhs.surname_)
                return true;
            return lhs.name_ < rhs.name_;
        }
    };

    class Company_AMN 
    {
    public:
        std::string name_;
        std::vector<uint64_t> employeeIds_;

        Company_AMN() = default;

        Company_AMN(const std::string& name, const std::vector<uint64_t>& employeeIds)
            : name_(name), employeeIds_(employeeIds)
        {
        }
    };

    class Employee_NGSN
    {
        std::string name_;
        std::string surname_;
    public:
        Employee_NGSN() = default;

        Employee_NGSN(const std::string& name, const std::string& surname)
            : name_(name), surname_(surname)
        {
        }

        std::string getName() const
        {
            return name_;
        }
        void setName(const std::string& name)
        {
            name_ = name;
        }
        std::string getSurname()const
        {
            return surname_;
        }
        void setSurname(const std::string& surname)
        {
            surname_ = surname;
        }

        friend bool operator<(const Employee_NGSN& lhs, const Employee_NGSN& rhs)
        {
            if (lhs.surname_ < rhs.surname_)
                return true;
            return lhs.name_ < rhs.name_;
        }
    };

    class Company_NGSN 
    {
        std::string name_;
        std::vector<uint64_t> employeeIds_;
        jsoncons::optional<double> rating_;
    public:
        Company_NGSN() = default;

        Company_NGSN(const std::string& name, const std::vector<uint64_t>& employeeIds)
            : name_(name), employeeIds_(employeeIds), rating_()
        {
        }

        std::string getName() const
        {
            return name_;
        }
        void setName(const std::string& name)
        {
            name_ = name;
        }
        const std::vector<uint64_t> getIds() const
        {
            return employeeIds_;
        }
        void setIds(const std::vector<uint64_t>& employeeIds)
        {
            employeeIds_ = employeeIds;
        }

        jsoncons::optional<double> getRating() const
        {
            return rating_;
        }
        void setRating(const jsoncons::optional<double>& rating)
        {
            rating_ = rating;
        }    
    };

    class Employee_AGSN
    {
        std::string name_;
        std::string surname_;
    public:
        Employee_AGSN() = default;

        Employee_AGSN(const std::string& name, const std::string& surname)
            : name_(name), surname_(surname)
        {
        }

        std::string getName() const
        {
            return name_;
        }
        void setName(const std::string& name)
        {
            name_ = name;
        }
        std::string getSurname()const
        {
            return surname_;
        }
        void setSurname(const std::string& surname)
        {
            surname_ = surname;
        }

        friend bool operator<(const Employee_AGSN& lhs, const Employee_AGSN& rhs)
        {
            if (lhs.surname_ < rhs.surname_)
                return true;
            return lhs.name_ < rhs.name_;
        }
    };

    class Company_AGSN 
    {
        std::string name_;
        std::vector<uint64_t> employeeIds_;
    public:
        Company_AGSN() = default;

        Company_AGSN(const std::string& name, const std::vector<uint64_t>& employeeIds)
            : name_(name), employeeIds_(employeeIds)
        {
        }

        std::string getName() const
        {
            return name_;
        }
        void setName(const std::string& name)
        {
            name_ = name;
        }
        const std::vector<uint64_t> getIds() const
        {
            return employeeIds_;
        }
        void setIds(const std::vector<uint64_t>& employeeIds)
        {
            employeeIds_ = employeeIds;
        }
    };

    class Employee_NCGN
    {
        std::string name_;
        std::string surname_;
    public:
        Employee_NCGN(const std::string& name, const std::string& surname)
            : name_(name), surname_(surname)
        {
        }

        std::string getName() const
        {
            return name_;
        }
        std::string getSurname()const
        {
            return surname_;
        }

        friend bool operator<(const Employee_NCGN& lhs, const Employee_NCGN& rhs)
        {
            if (lhs.surname_ < rhs.surname_)
                return true;
            return lhs.name_ < rhs.name_;
        }
    };

    class Company_NCGN 
    {
        std::string name_;
        std::vector<uint64_t> employeeIds_;
    public:
        Company_NCGN(const std::string& name, const std::vector<uint64_t>& employeeIds)
            : name_(name), employeeIds_(employeeIds)
        {
        }

        std::string getName() const
        {
            return name_;
        }
        const std::vector<uint64_t> getIds() const
        {
            return employeeIds_;
        }
    };

    class Employee_ACGN
    {
        std::string name_;
        std::string surname_;
    public:
        Employee_ACGN(const std::string& name, const std::string& surname)
            : name_(name), surname_(surname)
        {
        }

        std::string getName() const
        {
            return name_;
        }
        std::string getSurname() const
        {
            return surname_;
        }

        friend bool operator<(const Employee_ACGN& lhs, const Employee_ACGN& rhs)
        {
            if (lhs.surname_ < rhs.surname_)
                return true;
            return lhs.name_ < rhs.name_;
        }
    };

    class Company_ACGN 
    {
        std::string name_;
        std::vector<uint64_t> employeeIds_;
    public:
        Company_ACGN(const std::string& name, const std::vector<uint64_t>& employeeIds)
            : name_(name), employeeIds_(employeeIds)
        {
        }

        std::string getName() const
        {
            return name_;
        }
        const std::vector<uint64_t> getIds() const
        {
            return employeeIds_;
        }
    };

    template <class Employee>
    std::vector<Employee> fromIdsToEmployees(const std::vector<uint64_t>& ids)
    {
        static std::map<uint64_t, Employee> id_employee_map = {{1, Employee("John", "Smith")},{2, Employee("Jane", "Doe")}};

        std::vector<Employee> employees;
        for (auto id : ids)
        {
            employees.push_back(id_employee_map.at(id));
        }
        return employees;
    }

    template <class Employee>
    std::vector<uint64_t> fromEmployeesToIds(const std::vector<Employee>& employees)
    {
        static std::map<Employee, uint64_t> employee_id_map = {{Employee("John", "Smith"), 1},{Employee("Jane", "Doe"), 2}};

        std::vector<uint64_t> ids;
        for (auto employee : employees)
        {
            ids.push_back(employee_id_map.at(employee));
        }
        return ids;
    }

} // namespace
} // ns

JSONCONS_N_MEMBER_NAME_TRAITS(ns::Employee_NMN, 2,
    (name_, "employee_name"),
    (surname_, "employee_surname")
)

JSONCONS_N_MEMBER_NAME_TRAITS(ns::Company_NMN, 2,
    (name_, "company"),
    (employeeIds_, ns::fromIdsToEmployees<ns::Employee_NMN>, ns::fromEmployeesToIds<ns::Employee_NMN>, "resources"),
    (rating_, "rating")
)

JSONCONS_ALL_MEMBER_NAME_TRAITS(ns::Employee_AMN,
    (name_, "employee_name"),
    (surname_, "employee_surname")
)

JSONCONS_ALL_MEMBER_NAME_TRAITS(ns::Company_AMN,
    (name_, "company"),
    (employeeIds_, ns::fromIdsToEmployees<ns::Employee_AMN>, ns::fromEmployeesToIds<ns::Employee_AMN>, "resources")
)

JSONCONS_N_GETTER_SETTER_NAME_TRAITS(ns::Employee_NGSN, 2,
                                      (getName, setName, "employee_name"),
                                      (getSurname, setSurname, "employee_surname")
                                    )

JSONCONS_N_GETTER_SETTER_NAME_TRAITS(ns::Company_NGSN, 2,
  (getName, setName, "company"),
  (getIds, ns::fromIdsToEmployees<ns::Employee_NGSN>, ns::fromEmployeesToIds<ns::Employee_NGSN>, setIds, "resources"),
  (getRating, setRating, "rating")
)

JSONCONS_ALL_GETTER_SETTER_NAME_TRAITS(ns::Employee_AGSN,
    (getName, setName, "employee_name"),
    (getSurname, setSurname, "employee_surname")
)

JSONCONS_ALL_GETTER_SETTER_NAME_TRAITS(ns::Company_AGSN,
    (getName, setName, "company"),
    (getIds, ns::fromIdsToEmployees<ns::Employee_AGSN>, ns::fromEmployeesToIds<ns::Employee_AGSN>, setIds, "resources")
)

JSONCONS_N_CTOR_GETTER_NAME_TRAITS(ns::Employee_NCGN, 2,
                                      (getName, "employee_name"),
                                      (getSurname, "employee_surname")
                                    )

JSONCONS_N_CTOR_GETTER_NAME_TRAITS(ns::Company_NCGN, 2,
  (getName, "company"),
  (getIds, ns::fromIdsToEmployees<ns::Employee_NCGN>, ns::fromEmployeesToIds<ns::Employee_NCGN>, "resources")
)

JSONCONS_ALL_CTOR_GETTER_NAME_TRAITS(ns::Employee_ACGN,
    (getName, "employee_name"),
    (getSurname, "employee_surname")
)

JSONCONS_ALL_CTOR_GETTER_NAME_TRAITS(ns::Company_ACGN,
    (getName, "company"),
    (getIds, ns::fromIdsToEmployees<ns::Employee_ACGN>, ns::fromEmployeesToIds<ns::Employee_ACGN>, "resources")
)

using namespace jsoncons;

TEST_CASE("JSONCONS_N_GETTER_SETTER_NAME_TRAITS functional tests")
{
    SECTION("test 1")
    {
        std::vector<uint64_t> ids = {1,2};

        ns::Company_NGSN company("Example", ids);

        std::string output1;
        encode_json(company, output1);
        //std::cout << output1 << "\n\n";
        auto company2 = decode_json<ns::Company_NGSN>(output1);
        std::string output2;
        encode_json(company, output2);
        CHECK(output2 == output1);

        auto j = decode_json<json>(output2);
        CHECK(j.is<ns::Company_NGSN>());
        CHECK(j.is<ns::Company_AGSN>());
    }
} 

TEST_CASE("JSONCONS_ALL_GETTER_SETTER_NAME_TRAITS functional tests")
{
    SECTION("test 1")
    {
        std::vector<uint64_t> ids = {1,2};
        
        ns::Company_AGSN company("Example", ids);

        std::string output1;
        encode_json(company, output1);
        //std::cout << output1 << "\n\n";
        auto company2 = decode_json<ns::Company_AGSN>(output1);
        std::string output2;
        encode_json(company, output2);
        CHECK(output2 == output1);

        auto j = decode_json<json>(output2);
        CHECK(j.is<ns::Company_NGSN>());
        CHECK(j.is<ns::Company_AGSN>());
    }
} 

TEST_CASE("JSONCONS_N_CTOR_GETTER_NAME_TRAITS functional tests")
{
    SECTION("test 1")
    {
        std::vector<ns::Employee_NCGN> employees = {ns::Employee_NCGN("John", "Smith"), ns::Employee_NCGN("Jane", "Doe")};    

        std::string output1;
        encode_json_pretty(employees, output1);
        auto employees2 = decode_json<std::vector<ns::Employee_NCGN>>(output1);
        std::string output2;
        encode_json_pretty(employees2, output2);
        CHECK(output2 == output1);

        auto j = decode_json<json>(output2);
        CHECK(j.is<std::vector<ns::Employee_NCGN>>());
    }
    SECTION("test 2")
    {
        std::vector<uint64_t> ids = {1,2};

        ns::Company_NCGN company("Example", ids);

        std::string output1;
        encode_json(company, output1);
        //std::cout << output1 << "\n\n";
        auto company2 = decode_json<ns::Company_NCGN>(output1);
        std::string output2;
        encode_json(company, output2);
        CHECK(output2 == output1);

        auto j = decode_json<json>(output2);
        CHECK(j.is<ns::Company_NCGN>());
        CHECK(j.is<ns::Company_ACGN>());
    }
} 

TEST_CASE("JSONCONS_ALL_CTOR_GETTER_NAME_TRAITS functional tests")
{
    SECTION("test 1")
    {
        std::vector<uint64_t> ids = {1,2};
        
        ns::Company_ACGN company("Example", ids);

        std::string output1;
        encode_json(company, output1);
        //std::cout << output1 << "\n\n";
        auto company2 = decode_json<ns::Company_ACGN>(output1);
        std::string output2;
        encode_json(company, output2);
        CHECK(output2 == output1);

        auto j = decode_json<json>(output2);
        CHECK(j.is<ns::Company_NCGN>());
        CHECK(j.is<ns::Company_ACGN>());
    }
} 

TEST_CASE("JSONCONS_N_MEMBER_NAME_TRAITS functional tests")
{
    SECTION("test 1")
    {
        std::vector<uint64_t> ids = {1,2};

        ns::Company_NMN company("Example", ids);

        std::string output1;
        encode_json(company, output1);
        //std::cout << output1 << "\n\n";
        auto company2 = decode_json<ns::Company_NMN>(output1);
        std::string output2;
        encode_json(company, output2);
        CHECK(output2 == output1);

        auto j = decode_json<json>(output2);
        CHECK(j.is<ns::Company_NMN>());
        CHECK(j.is<ns::Company_AMN>());
    }
} 

TEST_CASE("JSONCONS_ALL_MEMBER_NAME_TRAITS functional tests")
{
    SECTION("test 1")
    {
        std::vector<uint64_t> ids = {1,2};
        
        ns::Company_AMN company("Example", ids);

        std::string output1;
        encode_json(company, output1);
        //std::cout << output1 << "\n\n";
        auto company2 = decode_json<ns::Company_AMN>(output1);
        std::string output2;
        encode_json(company, output2);
        CHECK(output2 == output1);

        auto j = decode_json<json>(output2);
        CHECK(j.is<ns::Company_NMN>());
        CHECK(j.is<ns::Company_AMN>());
    }
} 

