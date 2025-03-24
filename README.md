# Mini Search Engine

Imagine you have hundreds of text files in a folder, and you need to find a specific word or phrase inside them. Scrolling through each file manually would be a nightmare, right? 😵
That’s where our Mini Search Engine comes in! It’s a C program that acts like a Google for your text files – it scans all .txt files in a given folder, finds your search keyword, and ranks the files based on relevance. 📂🔍
________________________________________
🌟 What Does This Search Engine Do?

✅ Finds a keyword inside multiple .txt files 📄

✅ Counts how many times the keyword appears in each file 🔢

✅ Ranks the results – The more times a keyword appears, the higher the file ranks 📊

✅ Displays the most relevant files first (just like Google!) 🚀
________________________________________
🛠️ How It Works?

1️⃣ You enter a folder name (where your text files are stored).

2️⃣ You type the keyword you want to search for.

3️⃣ The program opens each file, scans for the keyword, and counts how many times it appears.

4️⃣ It sorts the files so that the most relevant ones (with the highest keyword count) appear first.

5️⃣ Finally, it displays the ranked results neatly.
________________________________________
🔎 Example Scenario

Let’s say you have a folder called docs/, and it contains three .txt files:

📄 resume.txt → "I have experience in C programming and data structures."

📄 project.txt → "C programming is widely used in system development."

📄 notes.txt → "Python and C programming have different use cases."

Now, if you search for "C programming", the program scans all files and gives you results like:
yaml
CopyEdit

🔍 Search Results for 'C programming':
---------------------------------------

📄 File: project.txt | 🔢 Keyword Count: 1

📄 File: resume.txt | 🔢 Keyword Count: 1

📄 File: notes.txt | 🔢 Keyword Count: 1

This means all files contain "C programming" once, so they’re equally relevant. But if one file had it multiple times, it would be ranked higher.
________________________________________
💡 Why is This Project Cool?

🔹 Super Useful – Can be used to search notes, logs, or project files easily.

🔹 Smart Ranking System – Sorts files based on how relevant they are.

🔹 Completely Automated – No need to open files one by one.

🔹 Scalable – Can be modified to search PDFs, Word docs, or even websites!
________________________________________
🚀 Future Upgrades

🔹 Add multi-threading to make searching faster. ⚡

🔹 Make it search PDFs & Word files instead of just .txt. 📑

🔹 Add a GUI (Graphical Interface) so users don’t have to type commands. 🎨

________________________________________
💭 Who Can Use This?

✅ Students – To find notes quickly inside multiple files.

✅ Writers – To search for repeated words in manuscripts.

✅ Developers – To search for error logs or documentation.

