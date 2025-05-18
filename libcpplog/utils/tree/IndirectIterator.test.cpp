#include <libcpplog/utils/tree/IndirectIterator.test.hpp>
#include <libcpplog/utils/tree/IndirectIterator.hpp>

#include <cassert>
#include <iostream>
#include <memory>
#include <source_location>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {

	cpplog::utils::tree::unit_test::IndirectIteratorTest test;

	test.testConstruction();

	test.testEqualComparison();
	test.testNotEqualComparison();

	test.testIncrement();
	test.testDecrement();

	test.testDereferenceOperator();
	test.testArrowOperator();

	test.testEndOfContainer();
	test.testRangeBasedForLoop();

	std::cout << "UT: utils::tree::IndirectIterator passed." << std::endl;
	return 0;
}

namespace cpplog::utils::tree::unit_test {

	void IndirectIteratorTest::testConstruction() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testConstruction()" << std::endl;

		using Element = std::shared_ptr<std::string>;
		using Container = std::vector<Element>;
		using Iterator = IndirectIterator<Container::iterator>;

		Element e1 = std::make_shared<std::string>("Hello");

		Container box{ e1 };

		Iterator it(box.begin());
		
		assert(&(*it) == e1.get());
	}

	void IndirectIteratorTest::testEqualComparison() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testEqualComparison()" << std::endl;


		using Element = std::unique_ptr<bool>;
		using Container = std::vector<Element>;
		using Iterator = IndirectIterator<Container::iterator>;

		Container box;
		box.push_back(std::make_unique<bool>(false));

		Iterator it(box.begin());

		assert(*it == false);
	}

	void IndirectIteratorTest::testNotEqualComparison() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testNotEqualComparison()" << std::endl;


		using Element = std::unique_ptr<bool>;
		using Container = std::vector<Element>;
		using Iterator = IndirectIterator<Container::iterator>;

		Container box;
		box.push_back(std::make_unique<bool>(false));

		Iterator it(box.begin());

		assert(*it != true);
	}

	void IndirectIteratorTest::testIncrement() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testIncrement()" << std::endl;

		using Element = std::unique_ptr<std::string>;
		using Container = std::vector<Element>;
		using Iterator = IndirectIterator<Container::iterator>;

		Container box;
		box.push_back(std::make_unique<std::string>("Hello"));
		box.push_back(std::make_unique<std::string>("Second"));
		box.push_back(std::make_unique<std::string>("Third"));

		Iterator it(box.begin());
		it++;
		it++;

		assert(*it == "Third");
	}

	void IndirectIteratorTest::testDecrement() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testDecrement()" << std::endl;

		using Element = std::unique_ptr<std::string>;
		using Container = std::vector<Element>;
		using Iterator = IndirectIterator<Container::iterator>;

		Container box;
		box.push_back(std::make_unique<std::string>("Hello"));
		box.push_back(std::make_unique<std::string>("Second"));
		box.push_back(std::make_unique<std::string>("Third"));

		Iterator it(box.begin());
		it++;
		it++;
		it--;

		assert(*it == "Second");
	}

	void IndirectIteratorTest::testDereferenceOperator() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testDereferenceOperator()" << std::endl;

		using Element = std::unique_ptr<std::string>;
		using Container = std::vector<Element>;
		using Iterator = IndirectIterator<Container::iterator>;

		Container box;
		box.push_back(std::make_unique<std::string>("Hello"));

		Iterator it(box.begin());

		assert(*it == "Hello");
	}

	void IndirectIteratorTest::testArrowOperator() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testArrowOperator()" << std::endl;

		class SomeClass {
		public:
			bool getValue() const { return true; }
		};

		using Element = std::unique_ptr<SomeClass>;
		using Container = std::vector<Element>;
		using Iterator = IndirectIterator<Container::iterator>;

		Container box;
		box.push_back(std::make_unique<SomeClass>());

		Iterator it(box.begin());

		assert(it->getValue() == true);
	}

	void IndirectIteratorTest::testEndOfContainer() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testEndOfContainer()" << std::endl;

		using Element = std::unique_ptr<std::string>;
		using Container = std::vector<Element>;
		using Iterator = IndirectIterator<Container::iterator>;
		
		Container box;
		box.push_back(std::make_unique<std::string>("Hello"));
		box.push_back(std::make_unique<std::string>("Second"));

		Iterator it;
		for (it = box.begin(); it != box.end(); ++it) {
			assert(*it == "Hello" || *it == "Second");
		}
		
		assert(it == box.end());
	}

	void IndirectIteratorTest::testRangeBasedForLoop() const {
		std::cout << std::source_location::current().file_name()
			<< "(" << std::source_location::current().line() << ")"
			<< ": Running testRangeBasedForLoop()" << std::endl;

		using Element = std::unique_ptr<std::string>;
		using Container = std::vector<Element>;
		using Iterator = IndirectIterator<Container::iterator>;

		Container box;
		box.push_back(std::make_unique<std::string>("Hello"));
		box.push_back(std::make_unique<std::string>("Second"));
		box.push_back(std::make_unique<std::string>("Third"));

		int count = 0;
		for (const auto& element : box) {
			assert(*element == "Hello" || *element == "Second" || *element == "Third");
			count++;
		}
		assert(count == 3);
	}

}