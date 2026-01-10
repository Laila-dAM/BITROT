import { state } from "./state.js"

export function renderStatus() {
  return `STATUS: ${state.status}\nLEVEL: ${state.level}\nXP: ${state.xp}`
}

export function renderXPBar() {
  const current = state.xp % 100
  const total = 100
  const filled = Math.floor((current / total) * 20)
  const empty = 20 - filled

  return `[${"#".repeat(filled)}${"-".repeat(empty)}]`
}
