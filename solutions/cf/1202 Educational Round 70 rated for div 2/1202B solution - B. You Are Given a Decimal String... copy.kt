const val INF = 1e9.toInt()

fun main(args: Array<String>) {
    val s = readLine()!!.map { it - '0' }
    val cf = Array(10) {Array(10) {0}}
    for (i in 1 until s.size)
        cf[s[i - 1]][s[i]]++

    for (x in 0..9) {
        for (y in 0..9) {
            val ds = Array(10) {Array(10) {INF + 7}}

            for (v in 0..9) {
                for (cx in 0..9) {
                    for (cy in 0..9) {
                        if (cx + cy == 0)
                            continue

                        val to = (v + cx * x + cy * y) % 10
                        ds[v][to] = minOf(ds[v][to], cx + cy)
                    }
                }
            }

            var res = 0
            for (v in 0..9) {
                for (to in 0..9) {
                    if (ds[v][to] > INF && cf[v][to] > 0) {
                        res = -1
                        break
                    }
                    res += (ds[v][to] - 1) * cf[v][to]
                }
                if (res == -1)
                    break
            }

            print("$res ")
        }
        println()
    }
}