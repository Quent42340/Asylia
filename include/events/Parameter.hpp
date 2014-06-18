/*
 * =====================================================================================
 *
 *       Filename:  Parameter.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  17/06/2014 18:48:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Quentin BAZIN, <quent42340@gmail.com>
 *        Company:  Deloptia
 *
 * =====================================================================================
 */
#ifndef PARAMETER_HPP_
#define PARAMETER_HPP_

class Parameter {
	public:
		Parameter();
		virtual ~Parameter();
		
		virtual void *value() = 0;
		
		bool isInteger() { return m_type == Type::IntParameter; }
		bool isFloat() { return m_type == Type::FloatParameter; }
		bool isString() { return m_type == Type::StringParameter; }
		
		enum Type {
			Undefined,
			IntParameter,
			FloatParameter,
			StringParameter
		};
		
	protected:
		Type m_type;
};

class IntParameter : public Parameter {
	public:
		IntParameter(int value);
		~IntParameter();
		
		void *value() { return (void*)&m_value; }
		
	private:
		int m_value;
};

class FloatParameter : public Parameter {
	public:
		FloatParameter(float value);
		~FloatParameter();
		
		void *value() { return (void*)&m_value; }
		
	private:
		float m_value;
};

class StringParameter : public Parameter {
	public:
		StringParameter(std::string value);
		~StringParameter();
		
		void *value() { return (void*)&m_value; }
		
	private:
		std::string m_value;
};

class ParameterList {
	public:
		ParameterList(const ParameterList &list);
		ParameterList();
		~ParameterList();
		
		void clear();
		
		Parameter *at(u16 id) const { return m_list[id]; }
		Parameter *operator[](u16 id) const { return m_list[id]; }
		
		u16 size() const { return m_list.size(); }
		
		void addIntParameter(int param) { m_list.push_back((Parameter*)(new IntParameter(param))); }	
		void addFloatParameter(float param) { m_list.push_back((Parameter*)(new FloatParameter(param))); }	
		void addStringParameter(std::string param) { m_list.push_back((Parameter*)(new StringParameter(param))); }	
		
	private:
		std::vector<Parameter*> m_list;
};

#endif // PARAMETER_HPP_