#pragma once

struct Texts {

	int id;
	sf::Text* current;
	Texts* next;

};

class TextList {

public:
	TextList();
	~TextList();
	
	/// <summary>
	/// Give a const char* that contains coordinates x and y
	/// </summary>
	/// <param name="x"> X axis </param>
	/// <param name="y"> Y axis </param>
	/// <returns></returns>
	const char* getCChar(float x, float y);

	Texts* getTexts();

	void setText(const char* text, int id);

	/// <summary>
	/// Add a text to the end of the texts struct
	/// </summary>
	/// <param name="text"></param>
	void addText(sf::Text* text);

	/// <summary>
	/// Draw every text contained in the structure
	/// </summary>
	/// <param name="target"></param>
	void draw(sf::RenderTarget& target);

private:
	Texts* texts = new Texts();

};
