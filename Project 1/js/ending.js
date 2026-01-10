import { state } from "./state.js"

export function getEnding() {
  if (state.flags.betrayed) return "betrayal"
  if (state.xp >= 120 && state.flags.escaped) return "good"
  if (state.xp >= 50 && state.flags.escaped) return "neutral"
  if (state.flags.escaped) return "bad"
  return null
}
