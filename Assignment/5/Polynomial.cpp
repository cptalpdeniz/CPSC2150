/*

THIS WHOLE ASSIGNMENT IS A FIASCO. THINGS USED TO WORK AND NOW DONT AND I DO NOT HAVE TIME TO FIX THIS
I'M AT A POINT WHERE I DONT EVEN WANT TO SUBMIT ANYTHING BEACUSE I WRITE/EDIT/ADD/SUBTRACT CODE AND NOTHING GETS FIXED OR SOME THINGS GET FIXED AND MORE THINGS COME UP 
THIS IS JUST A FUCKING MESS AND I DONT EVEN SLEEP ANYMORE SO JUST PLEASEEEE MARK IT FOR WHATEVER THAT'S WORKING OR YOU FEEL LIKE I WAS IN THE RIGHT PATH

THANK YOU SO MUCH

*/


#include "Polynomial.h"

Polynomial::Polynomial()
{
	head = nullptr;
	numOfTerms = 0;
}

Polynomial::~Polynomial()
{
	if (head == nullptr) {
		return;
	}
	Node* temp = head;
    Node* temp2 = head->next;
    while (temp->next != nullptr)
    {
        temp2 = temp->next;
        delete temp->term;
        delete temp;
        temp = temp2;
    }
    delete temp->term;
    delete temp;
}

Polynomial&	Polynomial::operator=(const Polynomial &p)
{
	if (this != &p)
	{
		Node* temp = p.head;
		while (temp != nullptr)
		{
			this->insert(*(temp->term));
			temp = temp->next;
		}
	}

	return (*this);
}

Polynomial::Polynomial(const Polynomial &p)
{
	head = nullptr;
	(*this) = p;
}

void Polynomial::insert(const Term t)
{
	if (head == nullptr)
	{
		head = new Node{new Term(t), nullptr};
	}
	else
	{
		Node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new Node{new Term(t), nullptr};
	}
	++numOfTerms;
}

Node* Polynomial::mergeList(Node* n, Node* n2)
{
	Node* tempHead;
	if (n == nullptr)
	{
		tempHead = n2;
	}
	else if (n2 == nullptr)
	{
		tempHead = n;
	}
	else if (*(n->term) >= *(n2->term))
	{
		tempHead = n;
		n = n->next;
	}
	else
	{
		tempHead = n2;
		n2 = n2->next;
	}
	Node* temp = tempHead;

	while (n != nullptr || n2 != nullptr)
	{
		if (n == nullptr)
		{
			temp->next = n2;
			break;
		}
		else if (n2 == nullptr)
		{
			temp->next = n;
			break;
		}
		else if (*(n->term) >= *(n2->term))
		{
			temp->next = n;
			n = n->next;
		}
		else
		{
			temp->next = n2;
			n2 = n2->next;
		}
		temp = temp->next;
	}
	return tempHead;

	/* 3RD VERSION

	Node* Polynomial::mergeList(Node* n, Node* n2)
	{
		Node* temp = nullptr;

		if (n->next == nullptr)
			return n;
		else if (n2->next == nullptr)
			return n2;
		
		if (*(n->term) >= *(n2->term))
		{
			temp = n;
			temp->next = mergeList(n->next, n2);
		}
		else
		{
			temp = n2;
			temp->next = mergeList(n, n2->next);
		}
		
		return temp;
	}
	*/
}

void Polynomial::split(Node* origin, Node* &dest1, Node* &dest2)
{
	int count = 0;
	Node* temp = origin;
	while (temp != nullptr)
	{
		++count;
		temp = temp->next;
	}

	temp = origin;
	for (int i = 0; i < count/2; ++i)
	{
		temp = temp->next;
	}
	dest2 = temp->next;
	temp->next = nullptr;
	dest1 = origin;

	/* 3RD VERSION
	
	void Polynomial::split(Node* origin, Node** dest1, Node** dest2)
	{
		Node* temp;
		Node* temp2;
		temp2 = origin;
		temp = origin->next;

		//increment temp1 twice while incrementing temp2 by once
		while (temp != nullptr)
		{
			temp = temp->next;
			if (temp != nullptr)
			{
				temp2 = temp2->next;
				temp = temp->next;
			}
		}

		(*dest1) = origin;
		*dest2 = temp2->next;
		temp2->next = nullptr;
	}
	*/
}

Node* Polynomial::sortHelper(Node* n)
{
	if (n == nullptr || n->next==nullptr || n->next->next == nullptr) { return n; }
	Node* temp = nullptr;
	Node* temp2 = nullptr;
	split(n, temp, temp2);
	temp = sortHelper(temp);
	temp2 = sortHelper(temp2);
	return mergeList(temp, temp2);

	/* 3RD VERSION OF MERGESORT
	`
	Node* Polynomial::sortHelper(Node** n)
	{
		Node* origin = *n;
		Node* temp;
		Node* temp2;

		if ((origin == nullptr) || (origin->next == nullptr))
			return nullptr;

		split(origin, &temp, &temp2);

		sortHelper(&temp);
		sortHelper(&temp2);

		return mergeList(temp, temp2);
	}
	*/
}

void Polynomial::sort()
{
	if (numOfTerms == 0)
		return;

	head = sortHelper(head);
	//0 check
	Node* temp = head;
	Node* temp2 = head->next;
	while (head->term->coeff == 0)
	{
		delete head;
		head = temp2;
		temp = temp2;
		temp2 = temp2->next;
	}
	
	while (temp != nullptr && temp->next != nullptr)
	{
		if (temp->next->term->coeff == 0)
		{
			temp2 = temp->next->next;
			delete temp->next;
			temp->next = temp2;
		}
		temp = temp->next;
	}

	/* 3RD VERSION

		void Polynomial::sort()
		{
			head = sortHelper(&(this->head));
		}
	*/
}

std::ostream& operator<<(std::ostream& out, const Polynomial &p)
{
	Node* temp = p.head;
	int coeff, degX, degY;
	while (temp != nullptr)
	{
		coeff = temp->term->getCoeff();

		//if coeff is 0, skip this term is 0*x*y is 0
		if (! coeff)
		{
			temp = temp->next;
			continue;
		}
		degX = temp->term->getX();
		degY = temp->term->getY();

		out << (coeff > 0 ? "+" : "") << coeff << "x^" << degX << "y^" << degY << " ";
		temp = temp->next;
	}
	return out;
}

Polynomial Polynomial::diff(bool respectToX) const
{
	Polynomial p;
	Node* temp = this->head;
	if (respectToX)
	{
		while (temp != nullptr)
		{
			p.insert(Term(temp->term->coeff*temp->term->deg_x, temp->term->deg_x - 1, temp->term->deg_y));
			temp = temp->next;
		}
	}
	else
	{
		while (temp != nullptr)
		{
			p.insert(Term(temp->term->coeff*temp->term->deg_y, temp->term->deg_x, temp->term->deg_y - 1));
			temp = temp->next;
		}
	}
	p.sort();
	return p;
}

Polynomial Polynomial::operator+(Polynomial const &p) const
{
	Node* temp, *tempHead, *temp2, *temp3;
	temp2 = this->head;
	temp3 = p.head;
	int numberOfTerms = 0;

	//check if one of the polynomial object is empty the return a new one;
	if (temp2 == nullptr)
	{
		return Polynomial(p);
	}
	else if (temp3 == nullptr)
	{
		return Polynomial(*this);
	}


	if (*(temp2->term) == *(temp3->term))
	{
		tempHead = new Node {new Term(temp2->term->coeff + temp3->term->coeff, temp2->term->deg_x, temp2->term->deg_y), nullptr};
		temp2 = temp2->next;
		temp3 = temp3->next;
	}
	else if (*(temp2->term) > *(temp3->term))
	{
		tempHead = new Node {new Term(temp2->term->coeff, temp2->term->deg_x, temp2->term->deg_y), nullptr};
		temp2 = temp2->next;
	}
	else
	{
		tempHead = new Node {new Term(temp3->term->coeff, temp3->term->deg_x, temp3->term->deg_y), nullptr};
		temp3 = temp3->next;
	}
	temp = tempHead;
	++numberOfTerms;

	while (temp2 != nullptr || temp3 != nullptr)
	{
		if (temp2 == nullptr)
		{
			temp->next = new Node {new Term(temp3->term->coeff, temp3->term->deg_x, temp3->term->deg_y), nullptr};
			temp3 = temp3->next;
		}
		else if (temp3 == nullptr)
		{
			temp->next = new Node {new Term(temp2->term->coeff, temp2->term->deg_x, temp2->term->deg_y), nullptr};
			temp2 = temp2->next;
		}
		else if (*(temp2->term) == *(temp3->term))
		{
			temp->next = new Node {new Term(temp2->term->coeff + temp3->term->coeff, temp2->term->deg_x, temp2->term->deg_y), nullptr};
			temp2 = temp2->next;
			temp3 = temp3->next;
		}
		else if (*(temp2->term) > *(temp3->term))
		{
			temp->next = new Node {new Term(temp2->term->coeff, temp2->term->deg_x, temp2->term->deg_y), nullptr};
			temp2 = temp2->next;
		}
		else if (*(temp3->term) > *(temp2->term))
		{
			temp->next = new Node {new Term(temp3->term->coeff, temp3->term->deg_x, temp3->term->deg_y), nullptr};
			temp3 = temp3->next;
		}
		temp = temp->next;
		++numberOfTerms;
	}
	//need to return sorted +
	tempHead = sortHelper(tempHead);
	return Polynomial(tempHead, numberOfTerms);
}

//BONUS 
//USED TO WORK 2 DAYS AGO, REVERTING STILL DOESNT FIX ANYTHING...
Polynomial Polynomial::operator*(Polynomial const &p) const
{
	Polynomial tempP;
	Node* temp = this->head;
	tempP.insert(*(temp->term) * (*(p.head->term)));
	std::cout << "this" << this->numOfTerms << " p:" << p.numOfTerms << std::endl;
	for (int i = 0; i < (this->numOfTerms -1); i++)
	{
		Node* tempPN = p.head->next;
		if (tempPN == nullptr)
			break;
		Polynomial tempP2;
		for (int j = 0; j < (p.numOfTerms -1); j++)
		{	
			if (temp == nullptr)
				break;
			if (temp->term->getCoeff())
			{
				temp = temp->next;
				continue;
			}
			tempP2.insert(*(temp->term) * *(tempPN->term));
			tempPN = tempPN->next;
			temp = temp->next;
		}
		tempP2.sort();
		tempP = tempP + tempP2;
	}
	return tempP;
}