import { openDialogue } from "./dialogue.js"

const npcs = {
  professor: {
    x: 10,
    y: 6,
    dialogue: "assets/ascii/dialogues/professor_branch.json"
  }
}

export function getNPCAt(x, y) {
  return Object.values(npcs).find(n => n.x === x && n.y === y)
}

export function interactWithNPC(npc) {
  if (!npc) return
  openDialogue(npc.dialogue)
}
