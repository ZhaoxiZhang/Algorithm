class Solution {
    fun countCharacters(words: Array<String>, chars: String): Int {
        val count = IntArray(26)
        chars.forEach { c ->
            count[c - 'a']++
        }
        var res = 0
        words.forEach loop@{ word ->
            val countClone = count.clone()
             word.forEach { c ->
                if (--countClone[c - 'a'] < 0) return@loop
            }
            res += word.length
        }
        return res
    }
}