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

// mainde butun termler eklendikten sonra cagirilcak
/*
Node* Polynomial::sortHelper(Node* n)
{
	if (n == nullptr || n->next==nullptr) 
		return n;
	Node* temp = nullptr;
	Node* temp2 = nullptr;
	split(n, temp, temp2);
	temp = sortHelper(temp);
	temp2 = sortHelper(temp2);
	return mergeList(temp, temp2);

}
*/

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

void Polynomial::sort()
{
	head = sortHelper(&(this->head));
	
	/*
	This code is only for debugging
	Node* t = temp;
	Node* t2 = temp2;
	std::cerr << "current lists: " << std::endl;
	while (!(t == nullptr || t2 == nullptr))
	{
		std::cout << "n1: " << std::endl;
		std::cerr << (t->term->getCoeff() > 0 ? "+" : "") << t->term->getCoeff() << "x^" << t->term->getX() << "y^" << t->term->getY() << " " << std::endl;
		std::cout << "n2: " << std::endl;
		std::cerr << (t2->term->getCoeff() > 0 ? "+" : "") << t2->term->getCoeff() << "x^" << t2->term->getX() << "y^" << t2->term->getY() << " " << std::endl;
		t = t->next;
		t2 = t2->next;
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
	int numOfTerms = 0;

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
	++numOfTerms;

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
		++numOfTerms;
	}
	//need to return sorted +
	//Not executing as sorting algorithm DOES NOT WORK
	tempHead = sortHelper(&tempHead);
	return Polynomial(tempHead, numOfTerms);
}

//BONUS
Polynomial Polynomial::operator*(Polynomial const &p) const
{
	Polynomial tempP;
	Node* temp = this->head;
	for (int i = 0; i < this->numOfTerms; i++)
	{
		Node* tempPN = p.head;
		Polynomial tempP2;
		for (int j = 0; j < p.numOfTerms && temp != nullptr; j++)
		{
			if (temp->term->getCoeff())
			{
				temp = temp->next;
				continue;
			}
			/*
			if (temp->term->getCoeff() != 0)
				std::cout << (temp->term->getCoeff() > 0 ? "+" : "") << temp->term->getCoeff() << "x^" << temp->term->getX() << "y^" << temp->term->getY() << " " << std::endl;
			*/
			tempP2.insert(*(temp->term) * *(tempPN->term));
			tempPN = tempPN->next;
			temp = temp->next;
		}
		tempP = tempP + tempP2;
	}
	return tempP;
}