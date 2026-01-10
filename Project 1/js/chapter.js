import { state } from "./state.js"

export function getChapter() {
  if (state.flags.escaped) return 3
  if (state.flags.camp_access) return 2
  return 1
}

export function getChapterTitle() {
  const c = getChapter()
  if (c === 1) return "CHAPTER 1: LOST"
  if (c === 2) return "CHAPTER 2: CAMP"
  if (c === 3) return "CHAPTER 3: ESCAPE"
}
